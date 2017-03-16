#!/usr/bin/python
import collections
import math
import string
import sys

R = 100
N = 3
M = 5
K = 7

def product(v):
    ans = 1
    for x in v:
        ans *= x
    return ans

def computeSubsetProducts(subs, s, table, i):
    if i == len(s):
        table[(tuple(s), product(subs))] += 1
        return
    computeSubsetProducts(subs, s, table, i+1)
    computeSubsetProducts(subs + [ s[i] ], s, table, i+1)
    

def analyzeSet(s, i, table):
    if i == N:
        computeSubsetProducts([], s, table, 0)
        return
    for j in range(2, M+1):
        analyzeSet(s + [ j ], i+1, table)
        

def precomputeSets():
    table = collections.defaultdict(int)  
            # Will map set, product to num ways to achieve product
    analyzeSet([], 0, table) 
    return table

def checkAllSets(s, i, prods, table):
    if i == N:
        ret = (s, product([ table[(tuple(s), p)] for p in prods ]))
        return ret
    bestScore = -1
    bestSet = []
    for j in range(2,M+1):
        curSet, curScore = checkAllSets(s + [ j ], i+1, prods, table)
        if curScore > bestScore:
            bestScore = curScore
            bestSet = curSet
    return (bestSet, bestScore)
        

def solve(prods, table):
    return ''.join([str(x) for x in checkAllSets([], 0, prods, table)[0]])
        

table = precomputeSets()
f = open(sys.argv[1])
NUM_CASES = int(f.readline())  # number of lines
for qq in range(NUM_CASES):
    line = f.readline().strip()  # ignore
    print "Case #1:"
    for r in range(R):
        line = f.readline().strip()
        prods = [ int(x) for x in line.split() ]
        print solve(prods, table)
