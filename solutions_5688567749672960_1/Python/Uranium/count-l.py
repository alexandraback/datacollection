#!/usr/bin/env python

def flip(n):
    return int(str(n)[::-1].lstrip('0'))

def solve(N):
    if N <= 20:
        return N
    if N % 10 == 0:
        return solve(N-1) + 1

    ndig = len(str(N))
    minred = 10**16
    for p in range(1, ndig):
        trunc_n = (N // (10 ** p) * (10 ** p)) + 1
        c_red = N - trunc_n
        fn = flip(trunc_n)
        c_red_fn = fn - 10**(ndig-1) + 1
        if fn == trunc_n:
            c_red_fn -= 1
        minred = min(minred, 1 + c_red + c_red_fn)
    return minred + solve(10**(ndig-1) - 1)

T = int(raw_input())
for t in xrange(T):
    N = int(raw_input())
    print "Case #%d: %d" % (t+1, solve(N))
