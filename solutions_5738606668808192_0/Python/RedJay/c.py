#!/usr/bin/python3

import sys
from functools import reduce
from math import sqrt
from fractions import gcd

SIZE=16
TOT=50

"""
print("getting primes...")
a = 2**SIZE      # smallest number needed
b = 10**(SIZE+1) # largest number needed
# uses sieve of eratosthenes
SIV = {x: True for x in list(range(a, b+1))}
for i in range(int(sqrt(a)),int(sqrt(b))):
    if SIV[x]:
        for j in range(i**2,b,i):
            SIV[j] = False
print("done getting primes!")
"""

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

# get a list of primes
print("Case #1: ")
j = TOT
curr = int("1" + "0"*(SIZE-2) + "1", 2)
while j != 0:
    currStr = bin(curr)[2:]
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
        print(currStr + " " + reduce(lambda x,y: x + " " + y, map(str,l)))
        j = j - 1
    # go to the next try
    curr = curr + 2
