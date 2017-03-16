#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def read_int(f): return int(f.readline().strip())
def read_l_int(f): return [int(e) for e in f.readline().strip().split()]

def solve(max_E, current_E, R, V):
    if not V: return 0
    candidates = []
    for spend_E in xrange(current_E+1):
        total = spend_E*V[0] + solve(max_E, min(max_E, current_E-spend_E+R), R,
                                     V[1:])
        candidates.append(total)
    return max(candidates)

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    f = open(sys.argv[1])
    n_cases = read_int(f)

    for i_case in range(1, n_cases+1):
        E, R, N = read_l_int(f)
        V = read_l_int(f)
        res = solve(E, E, R, V)
        print 'Case #%d:'%i_case, res
