#!/usr/bin/python3

from argparse import ArgumentParser
from pprint import pprint
import numpy as np

def debug(*args, level=1, **kwargs):
    if verbose >= level:
        print(*args, **kwargs)

def pdebug(*args, level=1, **kwargs):
    if verbose >= level:
        pprint(*args, **kwargs)

if __name__ == '__main__':
    p = ArgumentParser()
    p.add_argument('filename')
    p.add_argument('-v', '--verbose', action='count', default=0)
    p.add_argument('-n', '--limit', type=int)
    p.add_argument('-t', '--test', type=int)
    opts = p.parse_args()
    verbose = opts.verbose
    f = open(opts.filename)

    T = int(f.readline())
    if opts.limit is not None and T > opts.limit:
        T = opts.limit

    for casenum in range(1,T+1):
        A, B = [int(x) for x in f.readline().split()]
        p = np.fromstring(f.readline(), sep=' ')
        q = 1 - p.cumprod()

        debug(q)

        def solve():
            optimal = 1 + B + 1
            debug(optimal, level=2)
            for nbs in range(A):
                cost = 2 * nbs + (B-A) + 1
                cost += q[A-nbs-1] * (B + 1)
                debug(cost, level=2)
                if optimal > cost:
                    optimal = cost
            return '%.6f' % optimal

        output_str = solve()
        print('Case #%d:'%casenum, output_str)
