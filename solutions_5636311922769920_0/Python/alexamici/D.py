"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes
    python -u X.py < X-test.in > X-test.out
"""

import sys


def common_setup():

    pass


def case_reader(tc, infile):
    P = map(int, next(infile).split())
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, S=None, **kwargs):
    K, C, S = P
    values = [sum(i * K ** c for c in range(C)) + 1 for i in range(K)]
    res = ' '.join('%d' % r for r in values)
    return 'Case #{:d}: {}'.format(tc, res)


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print case_solver(**case)
