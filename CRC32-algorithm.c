#include <stdio.h>
#include <stdint.h>

uint32_t crc32(const uint8_t *data, size_t length, uint32_t polynomial, uint32_t initial_value) {
    uint32_t crc = initial_value;
    for (size_t i = 0; i < length; i++) {
        crc ^= (uint32_t)data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x80000000) { // Маска старшего бита crc
                crc = (crc << 1) ^ polynomial;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

int main() 
{
    const uint8_t data1[] = {0x31, 0x32, 0x33, 0x34}, data2[] = {};
    size_t len1 = sizeof(data1) / sizeof(*data1), len2 = 0;
    uint32_t polynomial = 0xEDB88320;
    uint32_t initial_value = 0xFFFFFFFF;
    
    printf("CRC1: 0x%X\n", crc32(data1, len1, polynomial, initial_value));
    printf("CRC2: 0x%x\n", crc32(data2, len2, polynomial, initial_value)); 
    
    return 0;
}
