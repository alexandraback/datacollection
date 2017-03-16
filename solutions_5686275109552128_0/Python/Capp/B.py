#!/usr/bin/env python

from sys import stdin
from math import ceil

T = int(stdin.readline())

for t in range(T):
    D = int(stdin.readline())
    wds = stdin.readline().split()
    P = [int(wd) for wd in wds]
    #print D, P

    mv = [1 for i in range(D)]
    mv_tot = 0
    pp = list(P)
    ret = []
    while True:
        maxpp = max(pp)
        ret.append(max(pp) + mv_tot)
        if maxpp <= 3: break

        pos = pp.index(maxpp)
        mv[pos] += 1
        mv_tot  += 1
        pp[pos] = int(ceil(float(P[pos]) / mv[pos]))
        continue
    #print ret

    print "Case #%d:" % (t+1),
    print min(ret)
