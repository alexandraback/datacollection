#! -*- coding: utf-8 -*-
import sys
from itertools import combinations

for i in xrange(1, 1 + int(sys.stdin.readline())):
    l = map(int, sys.stdin.readline().split())
    N = l[0]
    S = l[1:]
    d = {}
    breaknow = False
    print "Case #%d:" % (i)
    for j in range(1, N+1):
        if breaknow:
            break
        for subset in combinations(S, j):
            tmp = sum(subset)
            if tmp in d:
                for item in d[tmp]:
                    print item,
                print ""
                for item in subset:
                    print item,
                print ""
                breaknow = True
                break
            else:
                d[tmp] = subset
    if not breaknow:
        print "Impossible"

