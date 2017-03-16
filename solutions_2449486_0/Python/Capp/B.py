#!/usr/bin/env python

from sys import stdin



T = int(stdin.readline())

for t in range(T):
    print "Case #%d:" % (t+1),

    ## read
    N, M = stdin.readline().split()
    N = int(N)
    M = int(M)
    data = []
    for n in range(N): data.append([int(a) for a in stdin.readline().split()])

    #print data

    ret = "YES"
    for n in range(N):
        for m in range(M):
            rret = 1
            for k in range(N):
                if data[n][m] < data[k][m]:
                    rret = 0
                    break
                pass
            if rret == 1: continue
            rret = 1
            for k in range(M):
                if data[n][m] < data[n][k]:
                    rret = 0
                    break
                pass
            if rret == 1: continue
            ret = "NO"
            break
        if ret == "NO": break
        pass

    print ret
    pass
