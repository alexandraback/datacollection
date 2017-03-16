#!/usr/bin/env python

from sys import stdin

def L_sqrt(num):
    it = 1
    ret = 0
    while num >= it**2: it *= 10
    it /= 10
    while it >= 1:
        while num >= ret**2: ret += it
        ret -= it
        it /= 10
        pass
    #if ret ** 2 < num: ret += 1
    return ret

T = int(stdin.readline())

for t in range(T):
    print "Case #%d:" % (t+1),

    ## read
    wds = stdin.readline().split()
    r = int(wds[0])
    t = int(wds[1])

    ## solve
    a = 2
    b = 2*r-1
    c = - t
    #print a, b, c
    N = (L_sqrt(b * b - 4 * a * c) - b) / (2 * a)

    print N

    pass
