#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Qualification round - Problem A - Counting Sheep
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys


def solve(n):

    if n == 0:
        return 'INSOMNIA'

    digits = set()
    current = 0

    while len(digits) < 10:
        current += n
        [digits.add(d) for d in list(str(current))]

    return current


input_path = sys.argv[1]

with open(input_path, 'r') as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        N = int(input_file.readline())
        solution = solve(N)
        print 'Case #{0}: {1}'.format(case, solution)
