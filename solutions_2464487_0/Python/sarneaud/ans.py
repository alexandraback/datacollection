#!/usr/bin/env python
from sys import stdin, stdout
from itertools import *

def area(r):
    return r*r

def answer(data):
    r,paint = data

    ans = 0
    rn = 1
    while paint > 0:
        pr = area(r+rn) - area(r+rn-1)
        if pr <= paint:
            ans += 1
            rn += 2
        paint -= pr

    return ans

def cases(s):
    while 1:
        r,t = map(int, next(s).rstrip().split())
        yield (r,t)

if __name__ == '__main__':
    stdin.next()
    for n,c in enumerate(cases(stdin)):
        print "Case #%d: %s" % (n+1, answer(c))
