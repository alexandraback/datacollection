#!/usr/bin/env python

from sys import argv

script, filename = argv

with open(filename, 'r') as f:
    number_of_cases = int(f.readline().rstrip('\n'))
    case_number = 0
    while case_number < number_of_cases:
        case_number += 1
        line = f.readline().rstrip('\n')
        line = line + '+'
        length = len(line)
        old_length = length + 1
        while length < old_length:
            old_length = length
            line = line.replace('++', '+')
            line = line.replace('--', '-')
            length = len(line)
        print "Case #{}: {}".format(case_number, length - 1)
