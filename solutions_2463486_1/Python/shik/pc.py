#!/usr/bin/env python

import bisect
import math
import sys

def is_pal(x):
    return str(x) == str(x)[::-1]

sol = [1, 2, 3]
sol2 = []

def gen(now, rem, c1, c2, mid):
    if c1 + c2 > rem:
        return
    if rem == 0:
        n1 = str(now)
        n2 = str(now)[::-1]
        if mid == -1:
            sol.append(int(n1 + n2))
        else:
            sol.append(int(n1 + str(mid) + n2))
        return
    gen(now * 10, rem - 1, c1, c2, mid)
    if c1 > 0:
        gen(now * 10 + 1, rem - 1, c1 - 1, c2, mid)
    if c2 > 0:
        gen(now * 10 + 2, rem - 1, c1, c2 - 1, mid)

def _predo(N):
    ret = 0
    M = N // 2
    for i in xrange(1, 3): # first
        for j in xrange(3): # median
            if N % 2 == 0 and j > 0:
                continue
            for c1 in xrange(5):
                for c2 in xrange(2):
                    s = 2*i*i + j*j + 2*c1 + 8*c2
                    if s < 10 and c1 + c2 + 1 <= M:
                        gen(i, M - 1, c1, c2, -1 if N % 2 == 0 else j)

def predo():
    global sol2
    map(_predo, xrange(2, 51))
    sol.sort()
    sol2 = map(lambda x: x * x, sol)
    # print >> sys.stderr, len(sol), sol[-1], sol[-1] ** 2
    # print >> sys.stderr, all(map(lambda x: is_pal(x) and is_pal(x * x), sol))

def _solve(N):
    return bisect.bisect_right(sol2, N)

def solve():
    A, B = map(int, raw_input().split())
    return _solve(B) - _solve(A-1)

def main():
    predo()
    T = int(raw_input())
    for t in xrange(1, T+1):
        print 'Case #%d: %d' % (t, solve())

if __name__ == '__main__':
    main()
