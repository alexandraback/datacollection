#!/usr/bin/env python
from sys import stdin, stdout
from itertools import *

def f(R, k):
    return (2*R-3)*k + 2*k*(k+1)

def answer(data):
    r,paint = data

    ans = 0
    rn = 1

    lo = 1
    hi = paint+1

    while lo < hi:
        mid = (lo + hi) / 2
        if f(r, mid+1) <= paint:
            lo = mid+1
        else:
            hi = mid

    return lo 

def cases(s):
    while 1:
        r,t = map(int, next(s).rstrip().split())
        yield (r,t)

if __name__ == '__main__':
    stdin.next()
    for n,c in enumerate(cases(stdin)):
        print "Case #%d: %s" % (n+1, answer(c))
