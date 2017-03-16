#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Qualification round - Problem D - Fractiles
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys
import random


def solve(k, c, s):

    if s*c < k:
        return 'IMPOSSIBLE'

    to_guess = k
    tiles = []
    for student in xrange(s):

        targets = range(to_guess, to_guess-c, -1)
        targets = [max(t, 0) for t in targets]

        tile = 1
        for n_t, t in enumerate(targets):
            n_t += 1

            tile_val = ((k ** (c - n_t)) * (t-1))
            tile += tile_val if tile_val > 0 else 0

        if tile not in tiles:
            tiles.append(tile)

        to_guess -= c

    output = ' '.join(map(str,tiles))
    return output


input_path = sys.argv[1]

with open(input_path, 'r') as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        K, C, S = map(int, input_file.readline().strip().split())
        solution = solve(K, C, S)
        print 'Case #{0}: {1}'.format(case, solution)
