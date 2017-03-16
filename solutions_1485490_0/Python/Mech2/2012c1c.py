#!/usr/bin/env python

import os, sys


def solve (N, M):
    toys = 0
    cnt = 0
    while True:
        if not N or not M:
            break

        nn = N[cnt]
        nt = N[cnt+1]

        mm = M[cnt]
        mt = M[cnt+1]

        if nt == mt:
            toys += min(mm, nn)
            if mm > nn:
                N = N[2:]
                M[0] -= nn
            elif nn > mm:
                M = M[2:]
                N[0] -= mm
            else:
                N = N[2:]
                M = M[2:]
        else:
            res1 = solve(N[2:], M)
            res2 = solve(N, M[2:])
            toys += max(res1, res2)
            break

    return toys


fd = sys.stdin

line = fd.readline()
sets = int(line)+1

for case in range(1, sets):
    line = fd.readline().strip()

    N = [int(x) for x in fd.readline().strip().split()]
    M = [int(x) for x in fd.readline().strip().split()]
    
    nline = solve(N, M)
    print "Case #%s: %s" % (case, nline)

fd.close()
