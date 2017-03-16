#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p2.out", "w")

T = int(fin.readline())

for i in xrange(T):
    D = int(fin.readline())
    P = sorted(map(int, fin.readline().split()))
    ans = [n for n in xrange(1001)]
    for height in xrange(1, 1001):
        for x in P:
            ans[height] += (x-1) / height
    
    fout.write("Case #" + str(i+1) + ": " + str(min(ans[1:])) + "\n")
