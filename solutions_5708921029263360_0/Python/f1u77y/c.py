#! /usr/bin/python

import sys

t = int(input())

for _ in range(1, t + 1):
    j, p, s, k = (int(i) for i in input().split())
    bj = 1
    bp = 1
    bs = 1
    ga = []
    while bj <= j:
        u = min(k, j - bj + 1)
        v = min(k, p - bp + 1)
        w = min(k, s - bs + 1)
        a = ((bj + x, bp + y, bs + z)
             for x in range(u) for y in range(v) for z in range(w))
        ga += [' '.join(str(x) for x in ct) for ct in a]
        #print(ga, file=sys.stderr)
        bj += u
        bp += v
        bs += w
    print("Case #%d: %d" % (_, len(ga)))
    for s in ga:
        print(s)
    
