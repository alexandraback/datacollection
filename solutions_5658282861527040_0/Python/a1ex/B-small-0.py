import sys, string
from copy import copy, deepcopy
import gmpy
import time

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

for t in range(T):
    A,B,K = readlist()

    print ("Case #%d:" % (t+1)),
    #~ print >> sys.stderr, t

    x = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                x+=1
    print x
