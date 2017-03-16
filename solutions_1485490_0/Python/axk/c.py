#!/usr/bin/env python

from itertools import combinations_with_replacement

def calc(a, b, na, nb):
    if na > nb:
        na, nb = nb, na
        a, b = b, a
    res = 0
    for c in combinations_with_replacement(xrange(nb), na - 1):
        c = list(c)
        r = 0
        i = 0
        xa = a[0]
        k = 0 # index in c
        for j in xrange(nb):
            xb = b[2 * j]
            while k < len(c) and j == c[k]:
                if a[2 * i + 1] == b[2 * j + 1]:
                    xr = min(xa, xb)
                    r += xr
                    xa -= xr
                    xb -= xr
                i += 1
                xa = a[2 * i]
                k += 1
            if a[2 * i + 1] == b[2 * j + 1]:
                xr = min(xa, xb)
                r += xr
                xa -= xr
                xb -= xr
        res = max(res, r)
    return res

T = input()

for i in xrange(T):
    na, nb = [int(k) for k in raw_input().split()]
    a = [int(k) for k in raw_input().split()]
    b = [int(k) for k in raw_input().split()]
    print 'Case #%d: %d' % (i + 1, calc(a, b, na, nb))
