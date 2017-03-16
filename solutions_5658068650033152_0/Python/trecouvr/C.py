#!/usr/bin/env python3
import sys


def log(*a, **kw):
    print(*a,file=sys.stderr, **kw)


def solve(N,M,K):
    if M < N:
        N,M = M,N
    if N in (1,2):
        return K
    if K <= 5:
        return K
    r = M*M+1
    for n in range(3,N+1):
        rr = (K // n) * 2 + (n-2) * 2
        #log(rr)
        r = min(r, rr)
    return r


def main(t):
    N,M,K = (int(x) for x in input().split())
    r = solve(N,M,K)
    print("Case #%s: %s" % (t, r))


T = int(input())
for t in range(T):
    main(t+1)
