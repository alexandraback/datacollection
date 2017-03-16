#!/usr/bin/env python

import sys
from collections import defaultdict

def Solve(A, B, K):
    X = min(A, B)
    res = 0
    possible = defaultdict(int)
    for a in range(A):
        for b in range(B):
            possible[a & b] += 1
    for k in range(K):
        res += possible[k]
    return str(res)
        

inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0].strip())
line = 0
for t in range(T):
    A, B, K = map(int, inp[line+1].strip().split())
    print "Case #"+str(t+1)+": "+Solve(A, B, K)
    line += 1


    
