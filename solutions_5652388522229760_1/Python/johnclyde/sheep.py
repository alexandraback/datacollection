#!/usr/bin/env python

from sys import argv

script, filename = argv

with open(filename, 'r') as f:
    number_of_cases = int(f.readline().rstrip('\n'))
    case_number = 0
    while case_number < number_of_cases:
        case_number += 1
        N = int(f.readline().rstrip('\n'))
        result = 'INSOMNIA'
        seen = {} 
        if N > 0:
            result = 0
            while {int(digit) for digit in seen} != {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:
                result += N
                for digit in list('{}'.format(result)):
                    seen[digit] = 1
        print "Case #{}: {}".format(case_number, result)
