#!/usr/bin/python

import sys

def Ni(): return tuple(map(int, sys.stdin.readline().split()))
def Ns(): return tuple(map(int, sys.stdin.readline().split()))

T = Ni()[0]
for t in range(1, T + 1):
    A, B, K = Ni()
    answer = 0
    for i in range(A):
        for j in range(B):
            if (i&j) < K:
                #print i, j
                answer += 1
        
    print "Case #%d: %s" % (t, answer)

