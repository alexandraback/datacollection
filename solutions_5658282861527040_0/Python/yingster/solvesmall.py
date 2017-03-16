#!/usr/bin/env python
import numpy as np
import sys
import pdb
import math

sys.setrecursionlimit(15000)


def solve(A,B,K):
    winning = 0
    for i in range(A):
        for j in range(B):
            if i&j < K:
#                print str(i)+'\t'+str(j)+'\t'+str(i&j)

                winning += 1

    return winning
        



numcase = int(sys.stdin.readline())
for casenum in range(1,numcase+1):
    line = sys.stdin.readline().split()
    A = int(line[0])
    B = int(line[1])
    K = int(line[2])

    print 'Case #' + repr(casenum)+': '+ str(solve(A ,B, K))
    
