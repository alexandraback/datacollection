#!/usr/bin/env python

from sys import stdin

T = int(stdin.readline())

for t in range(T):
    wds = stdin.readline().split()
    N = int(wds[0])
    s = [float(wd) for wd in wds[1:]]
    if N != len(s):
        print >>stderr, "N != len(s)"
        exit(1)

    ss = sum(s)
    s2 = [f/ss for f in s]
    ret = [ -1 for f in s]
    total = 2.
    NN = N

    while True:
        nuke_ari = False
        for i in range(N):
            if s2[i] > total / NN:
                total -= s2[i]
                NN -= 1
                s2[i] = 0.
                ret[i] = 0.
                nuke_ari = True
                pass
            pass
        if not nuke_ari: break
        pass

    for i in range(N):
        if ret[i] == 0.: continue
        ret[i] = total / NN - s2[i]
        pass

    print "Case #%d:" % (t+1),
    for r in ret: print "%6f" % (r*100.),
    print
