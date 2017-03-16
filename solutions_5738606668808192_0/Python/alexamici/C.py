"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes
    python -u X.py < X-test.in > X-test.out
"""

import os
import sys


def common_setup():
    pass


def case_reader(tc, infile):
    P = map(int, next(infile).split())
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, S=None, **kwargs):
    import itertools as it
    import numpy as np

    def primes_upto(n, dtype='uint32'):
        P = np.arange(n + 1, dtype=dtype)
        P[1] = 0
        for p in xrange(2, int(n ** 0.5) + 1):
            if P[p]:
                P[p*p::p] = 0
        # return [p for p in P if p] # lower memory variant
        return P[P>0]

    primes = primes_upto(1000000)

    def from_base(n, b):
        assert 1 < b < 11, 'Unsupported %r' % locals()
        r = 0
        for i, d in enumerate(reversed(n)):
           r += int(d) * b ** i
        return r

    N, J = P

    res = []
    for items in it.product(['0', '1'], repeat= N - 2):
        tjc = '1' + ''.join(items) + '1'
        factors = []
        for b in range(2, 11):
            tjcb = from_base(tjc, b)
            for p in primes:
                if p >= tjcb ** 0.5:
                    break
                if tjcb % p == 0:
                    factors.append(p)
                    break
            else:
                break
        if len(factors) == 9:
            res.append((tjc, factors))
        if len(res) == J:
            break

    return 'Case #{:d}:\n{}'.format(tc, '\n'.join(r[0] + ' ' + ' '.join(str(p) for p in r[1]) for r in res))


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print case_solver(**case)
