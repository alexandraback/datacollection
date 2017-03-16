#!/usr/bin/python

import sys

def drange(start, stop, step):
    r = start
    while r < stop:
        yield r
        r += step

cases = int(sys.stdin.readline())
for case in range(1,cases+1):
    N = int(sys.stdin.readline().rstrip())
    attacks = dict()
    for _ in range(0, N):
        d,n,w,e,s,dd,dp,ds = map(int,sys.stdin.readline().rstrip().split(' '))
        for i in range(0,n):
            wM = w + i * dp
            eM = e + i * dp
            dM = d + i * dd
            if dM not in attacks:
                attacks[dM] = []
            attacks[dM].append([wM,eM,s+i*ds])
    wall = dict()
    W = 0
    for d in sorted(attacks.keys()):
        update = []
        for a in attacks[d]:
            ws = a[0]
            es = a[1]
            for i in drange(ws,es+0.5,0.5):
                if i not in wall:
                    wall[i] = 0
                if wall[i] < a[2]:
                    W += 1
                    update.append([ws,es,a[2]])
                    break
        for u in update:
            for i in drange(u[0], u[1]+0.5, 0.5):
                if i not in wall or wall[i] < u[2]:
                    wall[i] = u[2]
    print "Case #"+str(case)+": "+str(W)
