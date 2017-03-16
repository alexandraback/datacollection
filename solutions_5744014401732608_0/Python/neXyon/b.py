#!/usr/bin/python3
# coding: utf-8

import sys
import numpy as np

def compute(B, M):
    buildings_needed = (M - 1).bit_length() + 2
    
    if buildings_needed > B:
        return "IMPOSSIBLE"
    
    #max_ways = 2 ** (B - 1)
    #if max_ways < M:
    #    return "IMPOSSIBLE"
    
    result = np.zeros((B, B), dtype=np.uint8)
    
    ways_missing = M - 1
        
    for building in range(B - 2, -1, -1):
        num_buildings = B - building
        max_per_connection = 1 << (num_buildings - 4) if num_buildings > 4 else 1
        
        result[building, building + 1] = 1
        
        for target in range(building + 2, B):
            if ways_missing >= max_per_connection:
                ways_missing -= max_per_connection
                result[building, target] = 1
            max_per_connection //= 2
            if max_per_connection < 1:
                max_per_connection = 1
    
    result = 'POSSIBLE\n' + '\n'.join([''.join([chr(char + ord('0')) for char in line]) for line in result])
    
    return result

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline().strip()
    
    numbers = [int(x) for x in input_line.split(' ')]

    result = compute(*numbers)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)

