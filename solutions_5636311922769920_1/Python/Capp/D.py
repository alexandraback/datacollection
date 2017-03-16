#!/usr/bin/env python

from sys import stdin, stderr

for T in range(int(stdin.readline())):
    wds = stdin.readline().split()
    K = int(wds[0])
    C = int(wds[1])
    S = int(wds[2])

    print 'Case #%d:' % (T+1),

    if C * S < K:
        print 'IMPOSSIBLE'
        continue

    s = 0
    r = 0
    c = 0
    while s < S:
        r *= K
        r += s
        c += 1
        if c == C:
            print r + 1,
            r = 0
            c = 0
            pass
        s += 1
        pass
    if c != 0: print r + 1,
    print
