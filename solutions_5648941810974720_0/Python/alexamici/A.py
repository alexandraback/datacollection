"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes:
    python -u X.py < X-test.in > X-test.out
may be python 2 or 3.
"""
from __future__ import print_function

import os
import sys
#sys.setrecursionlimit(20000)


def common_setup():
    pass


def case_reader(tc, infile):
    T = next(infile)
    del infile
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, S=None, **kwargs):
    import collections as co
    C = dict(co.Counter(T))
    Z = C.get('Z', 0)
    if Z:
        C['E'] -= Z
        C['R'] -= Z
        C['O'] -= Z
    X = C.get('X', 0)
    if X:
        C['S'] -= X
        C['I'] -= X
    W = C.get('W', 0)
    if W:
        C['T'] -= W
        C['O'] -= W
    U = C.get('U', 0)
    if U:
        C['F'] -= U
        C['O'] -= U
        C['R'] -= U
    O = C.get('O', 0)
    if O:
        C['N'] -= O
        C['E'] -= O
    S = C.get('S', 0)
    if S:
        C['E'] -= S
        C['V'] -= S
        C['E'] -= S
        C['N'] -= S
    V = C.get('V', 0)
    if V:
        C['F'] -= V
        C['I'] -= V
        C['E'] -= V
    G = C.get('G', 0)
    if G:
        C['E'] -= G
        C['I'] -= G
        C['H'] -= G
        C['T'] -= G
    N = C.get('N', 0)
    if N:
        C['E'] -= N / 2
        C['I'] -= N / 2
    R = C.get('R', 0)
    res = '0' * Z + '1' * O + '2' * W + '3' * R + '4' * U + '5' * V + '6' * X + '7' * S + '8' * G + '9' * (N // 2)
    return 'Case #{:d}: {}'.format(tc, res)


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print(case_solver(**case))
