#!/usr/bin/python3
# coding: utf-8

import sys
import numpy as np

def compute(tiles, complexity, students):
    students_necessary = int(np.ceil(tiles / complexity))
    
    if students_necessary > students:
        return 'IMPOSSIBLE'
    
    path = np.arange(students_necessary * complexity)
    path[path >= tiles] = 0
    
    positions = []

    for student in range(students_necessary):
        position = 0
        for level in range(complexity):
            index = student * complexity + level
            position += path[index] * (tiles ** level)
        positions.append(str(position + 1))
        
    return ' '.join(positions)

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline()
    
    tiles, complexity, students = [int(x) for x in input_line.split(' ')]
    
    result = compute(tiles, complexity, students)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)

