# -*- coding: utf-8 -*-

T = int(raw_input())
for case in xrange(1, T + 1):
    A, B = map(int, raw_input().split())
    P = map(float, raw_input().split())

    mul = []
    p = 1.0
    for x in P:
        p *= x
        mul.append(p)

    es = []
    for nback in xrange(A):
        l = A - nback
        p = mul[l - 1]

        e1 = p * (B - l + 1) + (1 - p) * (B - l + 1 + B + 1)
        e2 = 1 + B + 1
        es.append(nback + min(e1, e2))

    print 'Case #%d: %.6f' % (case, min(es))

