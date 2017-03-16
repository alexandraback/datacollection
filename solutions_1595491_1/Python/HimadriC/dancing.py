#!/usr/bin/env python

import sys

T = int(sys.stdin.readline())

for zz in xrange(T):
    ret = 0
    line=map(int,sys.stdin.readline().rstrip().split())
    n=line[0]
    s=line[1]
    p=line[2]
    scores=line[3:]

    ret=0
    for x in scores:
        y = (x+(3-x%3)%3)/3
        if p <= y:
            ret += 1
        elif (x%3 == 0 or x%3 == 2) and y != 0 and p <= y+1 and s > 0:
            s -= 1
            ret += 1

    print "Case #%d: %d" % (zz+1,ret)
