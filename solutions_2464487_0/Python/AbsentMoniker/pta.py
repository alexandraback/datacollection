#!/usr/bin/python

import sys

if len(sys.argv) != 2:
    print "Usage: ./pta <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)
data = fin.readlines()
ntests = int(data[0].strip())
for i in range(1,ntests+1):
    info = data[i].strip().split()
    r = int(info[0])+1
    t = int(info[1])
    ringCnt = 0
    while t >= 0:
        t-= (2*r-1)
        r+=2
        if t>=0:
            ringCnt+=1
    print "Case #%d: %d"%(i,ringCnt)

sys.exit(0)
