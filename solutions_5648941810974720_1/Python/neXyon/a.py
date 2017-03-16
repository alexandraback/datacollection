#!/usr/bin/python3

import sys
import numpy as np

def compute_histogram(digits):
    histogram = np.zeros(26)

    for digit in digits:
        for letter in digit:
            histogram[ord(letter) - ord('A')] += 1
            
    return histogram

def compute_digits_order():
    digits = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

    letters = np.array([chr(letter + ord('A')) for letter in np.arange(26)])

    remaining_digits = list(digits)
    digits_order = []

    while len(remaining_digits) > 0:
        histogram = compute_histogram(remaining_digits)
        unique_letters = letters[histogram == 1]
        broken = False

        for digit in remaining_digits:
            for letter in unique_letters:
                if letter in digit:
                    digits_order.append((letter, digit))
                    remaining_digits.remove(digit)
                    broken = True
                    break
            if broken:
                break

    digits_order = [(ord(a) - ord('A'), digits.index(b), compute_histogram([b])) for a, b in digits_order]
    
    return digits_order

def compute(input_line, digits_order):
    input_histogram = compute_histogram([input_line])

    output_histogram = np.zeros(10, np.uint32)

    for index, digit, histogram in digits_order:
        count = input_histogram[index]
        output_histogram[digit] = count
        input_histogram -= count * histogram

    output = ''
    for digit, count in zip(range(10), output_histogram):
        output += chr(digit + ord('0')) * count
        
    return output

digits_order = compute_digits_order()

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline()
    
    result = compute(input_line.strip(), digits_order)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)

