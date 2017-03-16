#!/usr/bin/python3

import sys
from functools import reduce

def getNum():
    return int(sys.stdin.readline())

def getNums():
    return list(map(int, sys.stdin.readline().split(" ")))

def getTiles(k,c,s):
    if c*s < k:
        return "IMPOSSIBLE"
    else:
        retvals = []
        alltiles = list(range(1,k+1))
        for i in range(0,k,c):
            sometiles = alltiles[i:i+c]
            newtile = 1 # each tile must have at least one
            for j in range(len(sometiles)):
                newtile += k**j * (sometiles[j] - 1)
            retvals.append(newtile)
        return reduce(lambda x,y: x + " " + y, map(str, retvals))

t=getNum()
for i in range(1,t+1):
    k,c,s = getNums()
    print("Case #" + str(i) + ": " + getTiles(k,c,s))
