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
    T = next(infile).split()
    del infile
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, S=None, **kwargs):
    import itertools as it

    def partial(res_c, res_j, T0, T1):
        if len(T0) == 0:
            return res_c, res_j

        c = T0[0]
        j = T1[0]
        T0 = T0[1:]
        T1 = T1[1:]

        if c != '?':
            nc = [c]
        else:
            nc = list('0123456789')

        if j != '?':
            nj = [j]
        else:
            nj = list('0123456789')

        mm = [9999, '9999', '9999']
        for nnc, nnj in it.product(nc, nj):
            rc, rj = partial(res_c + nnc, res_j + nnj, T0, T1)
            if abs(int(rc) - int(rj)) < mm[0] or \
                (abs(int(rc) - int(rj)) == mm[0] and rc < mm[1]) or \
                (abs(int(rc) - int(rj)) == mm[0] and rc == mm[1] and rj < mm[2]):
                mm = [abs(int(rc) - int(rj)), rc, rj]
        return mm[1], mm[2]
    res_c, res_j = partial('0', '0', T[0], T[1])
    return 'Case #{:d}: {} {}'.format(tc, res_c[1:], res_j[1:])


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print(case_solver(**case))
