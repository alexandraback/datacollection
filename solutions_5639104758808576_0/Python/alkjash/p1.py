#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p1.out", "w")

T = int(fin.readline())

for i in xrange(T):
    Smax, Ss = fin.readline().split()
    Smax = int(Smax)
    Ss = map(int, list(Ss))
    Ss[0] -= 1
    for j in xrange(1, Smax + 1):
        Ss[j] = Ss[j-1] + Ss[j] - 1
    fout.write("Case #" + str(i+1) + ": " + str(max(0, -min(Ss))) + "\n")
