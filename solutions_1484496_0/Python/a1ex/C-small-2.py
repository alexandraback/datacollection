#from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

def sum(A, bits):
    s = 0
    for i in range(20):
        if bits & (1<<i):
            s += A[i]
    return s

def print_sum(A, bits):
    for i in range(20):
        if bits & (1<<i):
            print A[i],
    print ""

for k in range(T):
    A = readlist()[1:]
    #print >> sys.stderr, A
    print "Case #%d:" % (k+1)
    
    S = {};
    N = 1<<20;
    for i in range(N):
        s = sum(A, i)
        if s in S:
            j = S[s]
            print_sum(A, i)
            print_sum(A, j)
            break
        else:
            S[s] = i
    
