#!/usr/bin/python3
# coding: utf-8

import sys
import numpy as np

def compute(input_line):
    bool_input = np.array(list(input_line.strip()), np.character) == np.array('+', np.character)

    back_index = len(bool_input) - 1

    flips = 0

    while back_index >= 0:
        if not bool_input[back_index]:
            if bool_input[0]:
                front_index = 1
                while front_index <= back_index:
                    if not bool_input[front_index]:
                        flips += 2
                        bool_input[:front_index] = ~bool_input[front_index - 1::-1]
                        bool_input[:back_index + 1] = ~bool_input[back_index::-1]
                        break
                    front_index += 1
            else:
                flips += 1
                bool_input[:back_index + 1] = ~bool_input[back_index::-1]
        back_index -= 1

    return flips

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline()
    
    result = compute(input_line)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)

