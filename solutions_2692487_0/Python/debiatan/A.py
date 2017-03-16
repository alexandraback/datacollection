#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
#import numpy as np
#import itertools

def memo(f):
    cache = {}
    def wrap(*args):
        if args not in cache:
            cache[args] = f(*args)
        return cache[args]
    return wrap

def read_int(f): return int(f.readline().strip())
def read_l_int(f): return [int(e) for e in f.readline().strip().split()]

@memo
def solve(m, motes):
    if m == 1: return len(motes)
    if not motes: return 0
    if m>motes[0]: return solve(m+motes[0], motes[1:])
    else: return min(solve(m+(m-1), motes)+1, solve(m, motes[1:])+1)

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    f = open(sys.argv[1])
    n_cases = read_int(f)

    for i_case in range(1, n_cases+1):
        m, n_motes = read_l_int(f)
        motes = tuple(sorted(read_l_int(f)))
        corrections = solve(m, motes)

        print 'Case #%d:'%i_case, corrections
