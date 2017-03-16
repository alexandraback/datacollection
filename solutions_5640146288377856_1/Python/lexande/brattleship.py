#!/usr/bin/env python

import sys

def scorePerRow(w, c):
    if (c % w) == 0:
        return (c/w + w - 1)
    else:
        return (c/w + w)

t = int(sys.stdin.readline())
for i in range(0,t):
    rs, cs, ws = sys.stdin.readline().split(" ")
    print "Case #" + str(i+1) + ": " + str(scorePerRow(int(ws),int(cs))*int(rs))
