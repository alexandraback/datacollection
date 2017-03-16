# -*- coding: utf-8 -*-

from fractions import Fraction as F


def C(n, r):
    _ = lambda x, y: reduce(lambda a, b: a * b, xrange(x, y + 1), 1)
    if n / 2 < r:
        r = n - r
    return _(n - r + 1, n) / _(1, r)


T = int(raw_input())
for test_id in xrange(1, T + 1):
    N, X, Y = map(int, raw_input().split())

    f = lambda d: d * (2 * d - 1)
    d = (abs(X) + Y) / 2 + 1
    n = f(d)
    n_before = f(d - 1)

    if n <= N:
        p = F(1)
    elif N <= n_before:
        p = F(0)
    elif X == 0:
        if N < n:
            p = F(0)
        else:
            p = F(1)
    else:
        a = N - n_before
        assert 1 <= a
        l = 2 * (d - 1)
        assert 0 <= Y <= l
        if a <= l:
            if Y < a:
                p = 0
                for i in xrange(Y + 1):
                    p += C(a, i)
                p = 1 - F(p, 2 ** a)
            else:
                p = F(0)
        else:
            b = a - l
            assert 1 <= b
            if Y < b:
                p = F(1)
            else:
                p = 0
                for i in xrange(Y + 1, a + 1):
                    p += C(a, i)
                p = F(p, 2 ** a)

    print 'Case #{}: {:6f}'.format(test_id, float(p))
