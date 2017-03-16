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

def rev(x):
    return int(str(x)[::-1])

T = readint()

for t in range(T):
    N = readint()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),

    Q = [1]
    C = [1]
    QS = set(Q)
    k = 0
    while k < len(Q):
        s = Q[k]
        c = C[k]
        if s == N:
            print c
            break

        if s+1 not in QS and s+1 <= N:
            Q.append(s+1)
            C.append(c+1)
            QS.add(s+1)
        
        r = rev(s)
        if r not in QS and r <= N:
            Q.append(r)
            QS.add(r)
            C.append(c+1)
        
        k += 1
    
