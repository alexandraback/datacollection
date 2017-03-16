#!/usr/bin/env python

import sys

def canexpress(denoms, value):
    if len(denoms) == 0:
       return False
    if value in denoms:
       return True
    if value > denoms[-1]:
       return canexpress(denoms[:-1], value-denoms[-1])
    else:
       return canexpress(denoms[:-1], value)


t = int(sys.stdin.readline())
for i in range(1,t+1):
    c, d, v = map(int, sys.stdin.readline().split(' '))
    denoms = map(int, sys.stdin.readline().split(' '))
    for value in range(1,v+1):
        if not canexpress(denoms, value):
            denoms.append(value)
            denoms.sort()
    print "Case #" + str(i) + ": " + str(len(denoms) - d)
