"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes
    python -u X.py < X-test.in > X-test.out
"""

import os
import sys
sys.setrecursionlimit(20000)


def common_setup():
    pass

S = {'': 0}

def case_reader(tc, infile):
    T = next(infile).strip()
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, **kwargs):
    #import collections as co
    #import functools32 as ft
    import itertools as it
    #import math as ma
    #import networkx as nx
    #import numpy as np
    #import operator as op
    #import random as rn
    #import re
    #import scipy as sp
    #import heapq as hq

    def flip(T, slice_stop):
        return ''.join('+' if t == '-' else '-' for t in reversed(T[:slice_stop])) + T[slice_stop:]

    def reduced(T):
        tail_index = len(T) - T[::-1].find('-')
        if tail_index > len(T):
            return ''
        else:
            return T[:tail_index]

    def best(T):
        T = reduced(T)
        if T not in S:
            if T[0] == '-':
                S[T] = best(flip(T, len(T))) + 1
            else:
                S[T] = best(flip(T, T.index('-'))) + 1
        return S[T]

    return 'Case #{:d}: {}'.format(tc, best(T))


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print case_solver(**case)
