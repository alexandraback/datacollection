#!/usr/bin/env python
from sys import stdin, stdout
from itertools import *

def f(E,i):
    global memo
    key = (E,i)
    if key in memo:
        return memo[key]

    ret = 0

    if i < len(v):
        for e in xrange(E+1):
            val = e*v[i] + f(min(E-e+R, mE), i+1)
            ret = max(ret, val)
    
    memo[key] = ret
    return ret

def answer(data):
    global E,R,v,mE, memo
    E,R,N,v = data
    mE = E
    memo = {}

    return f(E, 0)

def cases(s):
    while 1:
        E,R,N = map(int, next(s).rstrip().split())
        v = map(int, next(s).rstrip().split())
        yield (E,R,N, v)

if __name__ == '__main__':
    stdin.next()
    for n,c in enumerate(cases(stdin)):
        print "Case #%d: %s" % (n+1, answer(c))
