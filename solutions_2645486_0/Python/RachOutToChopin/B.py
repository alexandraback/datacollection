#!/usr/bin/python
import math
import string
import sys

def findNextLarger(vArr, i):
    for j in range(i+1, len(vArr)):
        if vArr[j] > vArr[i]:
            return j
    return None

def solve(E, R, N, vArr):
    energy = E
    value = 0
    for i in range(N):
        nearestLarger = findNextLarger(vArr, i)        
        if nearestLarger == None:
            value += energy * vArr[i]
            energy = R
        else:
            energyUsed = min(energy, energy - E + (nearestLarger - i) * R)
            if energyUsed < 0: 
                energyUsed = 0
            energy -= energyUsed
            value += vArr[i] * energyUsed
            energy += R
    return value
        

f = open(sys.argv[1])
NUM_CASES = int(f.readline())  # number of lines
for qq in range(NUM_CASES):
    line = f.readline().strip()
    E, R, N = [ int(x) for x in line.split() ]
    line = f.readline().strip()
    vArr = [ int(x) for x in line.split() ] 
    print "Case #%d: %s" % (qq+1, solve(E, R, N, vArr))
