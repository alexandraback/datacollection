#!/usr/bin/env python

def solve(A, B, K):
    res = 0
    for X in xrange(A):
        for Y in xrange(B):
            if (X & Y) < K:
                res += 1
    return res

T = int(raw_input())
for x in xrange(1, T + 1):
    A, B, K = [int(v) for v in raw_input().split()]
    print 'Case #%d: %s' % (x, solve(A, B, K))
