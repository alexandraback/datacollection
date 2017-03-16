import sys, string
from copy import copy, deepcopy
import gmpy
import time

import sys
sys.setrecursionlimit(1000000)

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readbinlist():
	return [int(x,2) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

for t in range(T):
    R,C,W = readlist()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    
    score = (R-1) * C/W
    
    while C > W:
        score += 1
        C -= W
    
    print score + W
