#from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

for k in range(T):
    
    N = int(sys.stdin.readline())
    V = {}
    for i in range(N):
        L = readlist()
        V[i+1] = L[1:]
    
    print "Case #%d:" % (k+1),
    
    found=0
    for X in range(1,N+1):
        Q = [X]
        N = {}
        N[X] = 1;
        i = 0
        while i < len(Q):
            for v in V[Q[i]]:
                Q.append(v)
                if v in N:
                    print "Yes"
                    found=1
                    break
                else:
                    N[v] = 1
            if found:
                break
            i += 1
    if not found:
        print "No"
    
    
    #print >> sys.stderr, A
    
    
