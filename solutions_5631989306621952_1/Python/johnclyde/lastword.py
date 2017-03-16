#!/usr/bin/env python

from sys import argv

script, filename = argv

with open(filename, 'r') as f:
    number_of_cases = int(f.readline().rstrip('\n'))
    case_number = 0
    while case_number < number_of_cases:
        case_number += 1
        line = f.readline().rstrip('\n')
        letters = []
        for letter in line:
            # print "letter is {}".format(letter)
            if len(letters) == 0 or letters[0] > letter:
                letters.append(letter)
            else:
                letters.insert(0, letter)

        print "Case #{}: {}".format(case_number, ''.join(letters))
