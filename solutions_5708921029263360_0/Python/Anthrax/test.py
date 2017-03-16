import sys
sys.setrecursionlimit(100000000)

import itertools
import numpy

answer = ""


def rec(pick,J,P,S,K):
    pass

def inc(D,x):
    if not x in D:
        D[x] = 1
    else:
        D[x] += 1

def solve(J,P,S,K):
    A = []
    for j in range(J):
        for p in range(P):
            for s in range(S):
                for k in range(K):
                    A.append((j+1,s+1,p+1))


    A = sorted(list(set(A)))
    bestO = []

    for i in range(100):
        pA = numpy.random.permutation(A)
        pA = tuple(map(tuple, pA))
        JP = {}
        PS = {}
        JS = {}

        O = []
        for a in pA:
            x = a[0:2]
            y = a[1:3]
            z = a[0:3:2]
            if ((not x in JP) or (JP[x] < K)) and \
            ((not y in PS) or (PS[y] < K)) and \
            ((not z in JS) or (JS[z] < K)):
                O.append(a)
                inc(JP,x)
                inc(PS,y)
                inc(JS,z)
        if len(O)>len(bestO):
            bestO = O
    
    print(len(O))
    for o in O:
        print(*o)
    
    

    
T = int(input())

for t in range(T):
    J,P,S,K = [int(x) for x in input().split()]
    
    print("Case #%d: " % (t+1), end="")

    solve(J,P,S,K)

