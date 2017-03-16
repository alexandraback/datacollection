import os, sys
import math
from pprint import *

inFile = None
outFile = None


def printAnswer(case, answer):
    outFile.write('Case #{0}: {1}\n'.format(case+1, answer))

def solveCase2(caseNo):
    (E,R,n) = map(int, inFile.readline().strip().split())
    V = map(int, inFile.readline().strip().split())

    
    Max = V[-1]
    Maxs = [0] * n
    for i in range(n-1, -1, -1):
        if V[i] > Max:
            Max = V[i]
        Maxs[i] = Max

    # print 'caseNo', caseNo
    
    ans = 0
    energy = E
    for (i, value) in enumerate(V):
        if Maxs[i] == V[i]:
            ans += energy*V[i]
            energy = R
        else:
            if energy + R > E:
                energyThatCanBeUsed = min(energy, (energy+R)-E)
                ans += energyThatCanBeUsed * V[i]

            energy = min(E, energy + R)
        
    printAnswer(caseNo, ans)


def solveCase(caseNo):
    (E,R,n) = map(int, inFile.readline().strip().split())
    V = map(int, inFile.readline().strip().split())

    memory = {}
    def go(energy, idx):
        if idx >= n:
            return 0

        p = (energy, idx)
        if p in memory:
            return memory[p]

        ans = 0
        gain = 0
        while energy >= 0:
            ans = max(ans, go(min(E,energy+R), idx+1) + gain)
            gain += V[idx]
            energy -= 1

        memory[p] = ans
        return memory[p]

    ans = go(E, 0)
    printAnswer(caseNo, ans)

def main():
    cases = int(inFile.readline().strip())
    for case in range(cases):
        solveCase(case)

if __name__ == '__main__':
    inFile = open('in.txt','rt')
    outFile = open('out.txt', 'wt')
    main()