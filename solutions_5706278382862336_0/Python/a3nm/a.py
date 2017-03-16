#!/usr/bin/python

import sys
from fractions import gcd

ncases = int(sys.stdin.readline())

for ncase in range(ncases):
    l = sys.stdin.readline()
    f = l.split('/')
    p = int(f[0])
    q = int(f[1])
    g = gcd(p, q)
    p /= g
    q /= g
    if q & (q-1) != 0:
        print("Case #%d: impossible" % (ncase+1))
        continue
    ratio = float(p)/q
    base = 1
    gen = 0
    while base > ratio and gen <= 40:
        base *= .5
        gen += 1
    if base > 40:
        print("Case #%d: impossible" % (ncase+1))
        continue
    print("Case #%d: %d" % (ncase+1, gen))


    
