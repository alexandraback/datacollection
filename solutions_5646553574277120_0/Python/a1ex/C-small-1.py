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

def check(D, V):
    S = set()
    for b in range(1 << len(D)):
        s = 0
        for i in range(len(D)):
            if b & (1<<i):
                s += D[i]
        S.add(s)
    
    missing = []
    for i in range(V+1):
        if i not in S:
            missing.append(i)
    return missing

for t in range(T):
    C,D,V = readlist()
    D = readlist()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    
    #~ print D
    missing = check(D,V)
    
    if not missing:
        print 0
        continue
    
    Q = [sorted(D)]
    C = [0]
    k = 0
    while k < len(Q):
        d = Q[k]
        c = C[k]
        missing = check(d,V)
        if not missing:
            print c
            break
        
        for m in missing[:1]:
            new = sorted(d+[m])
            if new not in Q:
                Q.append(new)
                C.append(c+1)
            
        k += 1
