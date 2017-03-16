#!/usr/bin/python3

import time
import sys
from functools import reduce
from math import sqrt
from fractions import gcd
import multiprocessing

SIZE=32
TOT=500
MAXTIME = 5

ALLVALS = {}

def getProof(x):
    if x in ALLVALS:
        return ALLVALS[x]
    for i in range(int(sqrt(x))):
        ret = gcd(i,x)
        if ret != 1 and ret != x:
            ALLVALS[x] = ret
            return ret
    ALLVALS[x] = 0
    return 0

def tryNum(currStr,currTry,strList): 
    fail = False
    l = []
    for i in range(2,11):
        d = getProof(int(currStr,i))
        if d == 0:
            fail = True
            break
        else:
            l.append(d)
    if not fail:
        strList[currTry] = currStr + " " + reduce(lambda x,y: x + " " + y, map(str,l))

# get a list of primes
print("Case #1: ")
j = TOT
curr = int("1" + "0"*(SIZE-2) + "1", 2)
manager = multiprocessing.Manager()
l = manager.list([""]*TOT)
while j != 0:
    currStr = bin(curr)[2:]
    p = multiprocessing.Process(target=tryNum, args=(currStr,j-1,l,))
    p.start()
    p.join(0.25)
    if p.is_alive():
        p.terminate()
    else:
        if l[j-1] != "":
            print(l[j-1])
            j = j - 1
    # go to the next try
    curr = curr + 2
