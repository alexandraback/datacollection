#!/usr/bin/env python3
"""
Google Code Jam
2015 Round 1C

Problem B. Typewriter Monkey

@author: yamaton
@date: 2015-05-10
"""

import itertools
import functools
import operator
import collections
import math
import sys

@functools.lru_cache(maxsize=None)
def possible(n, xs):
    if n == 0:
        return True
    elif not xs:
        return False
    elif xs[0] > n:
        return False
    else:
        return possible(n - xs[0], xs[1:]) or possible(n, xs[1:])

# Limit C == 1
def bruteforce(xs, C, D, V):
    xs = tuple(xs)
    for i in range(1, V+1):
        if not possible(i, xs):
            xs = tuple(sorted(list(xs) + [i]))
    return len(xs) - D


if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #%d: " % (i + 1), end='')
        C, D, V = [int(s) for s in input().strip().split()]
        xs = [int(s) for s in input().strip().split()]
        assert len(xs) == D

        result = bruteforce(xs, C, D, V)
        print(result)
        
        print('\n--------- case #%d -------' % (i + 1), file=sys.stderr)
        print('xs =', xs, file=sys.stderr)
        print('C, D, V =', (C, D, V), file=sys.stderr)
        print('result =', result, file=sys.stderr)