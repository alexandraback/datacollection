#!/usr/bin/env python

from collections import Counter

for i in xrange(int(raw_input())):
    firsts = []
    seconds = []
    fakes = 0
    for j in xrange(int(raw_input())):
        f, s = raw_input().split()
        firsts.append(f)
        seconds.append(s)
    firstCnt = Counter(firsts)
    secondCnt = Counter(seconds)
    for f,s in zip(firsts, seconds):
        if (firstCnt[f] > 1) and (secondCnt[s] > 1):
            fakes += 1

    print "Case #{}: {}".format(i+1, fakes)

