#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Qualification round - Problem B - Revenge of the Pancakes
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys


def solve(pancakes):

    positions = ['+', '-']
    current = 0
    changes = 0

    for p in pancakes[::-1]:
        if p != positions[current]:
            current = (current + 1) % 2
            changes += 1

    return changes


input_path = sys.argv[1]

with open(input_path, 'r') as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        stack = list(input_file.readline().strip())
        solution = solve(stack)
        print 'Case #{0}: {1}'.format(case, solution)
