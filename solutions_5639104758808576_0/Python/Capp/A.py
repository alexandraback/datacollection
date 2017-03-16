#!/usr/bin/env python

from sys import stdin

T = int(stdin.readline())

for t in range(T):
    line = stdin.readline()
    wds = line.split()
    Smax = int(wds[0])
    S = []
    for c in wds[1]: S.append(int(c))

    need = 0
    stand = S[0]
    for i in range(Smax):
        #print "debug:", need, stand, S[i+1]
        if stand < i+1:
            need += i+1 - stand
            stand = i+1
            pass
        stand += S[i+1]
        pass

    print "Case #%d:" % (t+1),
    print need
