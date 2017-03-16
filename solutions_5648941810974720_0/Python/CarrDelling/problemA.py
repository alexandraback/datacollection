#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Round 1 - Problem A -
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys
from collections import defaultdict

zero = {'Z': 1, 'E': 1, 'R': 1, 'O': 1}
six = {'S': 1, 'I': 1, 'X': 1}
two = {'T': 1, 'W': 1, 'O': 1}
four = {'F': 1, 'O': 1, 'U': 1, 'R': 1}
eight = {'E': 1, 'I': 1, 'G': 1, 'H': 1, 'T': 1}
three = {'T': 1, 'H': 1, 'R': 1, 'E': 2}
five = {'F': 1, 'I': 1, 'V': 1, 'E': 1}
seven = {'S': 1, 'E': 2, 'V': 1, 'N': 1}
one = {'O': 1, 'N': 1, 'E': 1}
nine = {'N': 2, 'I': 1, 'E': 1}


def solve(word):

    chars = defaultdict(int)
    numbers = []

    for c in word:
        chars[c] += 1

    while 'Z' in chars:
        for z in zero:
            chars[z] -= zero[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(0)

    while 'X' in chars:
        for z in six:
            chars[z] -= six[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(6)

    while 'W' in chars:
        for z in two:
            chars[z] -= two[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(2)

    while 'U' in chars:
        for z in four:
            chars[z] -= four[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(4)

    while 'G' in chars:
        for z in eight:
            chars[z] -= eight[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(8)

    while 'T' in chars:
        for z in three:
            chars[z] -= three[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(3)

    while 'F' in chars:
        for z in five:
            chars[z] -= five[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(5)

    while 'V' in chars:
        for z in seven:
            chars[z] -= seven[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(7)

    while 'O' in chars:
        for z in one:
            chars[z] -= one[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(1)

    while 'I' in chars:
        for z in nine:
            chars[z] -= nine[z]
            if chars[z] == 0:
                chars.pop(z)
        numbers.append(9)

    output = ''.join(map(str,sorted(numbers)))
    return output


input_path = sys.argv[1]

with open(input_path) as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        input_word = input_file.readline().strip()
        solution = solve(input_word)
        print 'Case #{0}: {1}'.format(case, solution)
