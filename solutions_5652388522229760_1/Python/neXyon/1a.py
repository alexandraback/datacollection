#!/usr/bin/python3

import sys
import numpy as np

def compute(number):
    if number == 0:
        return 'INSOMNIA'
    
    seen = np.zeros(10, np.bool)

    count = 0

    while np.sum(seen) != 10:
        count += 1
        current = count * number

        while current > 0:
            seen[current % 10] = True
            current //= 10

    return count * number

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    number = int(input_file.readline())
    
    result = compute(number)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)

input_file.close()
output_file.close()

