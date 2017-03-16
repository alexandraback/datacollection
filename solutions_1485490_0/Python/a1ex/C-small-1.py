#from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

def solve(Lb, Lt):
    # aici luam decizii
    # D1: nu arunc primul tip de cutii
    # D2: le arunc
    
    if not Lt: return 0
    if not Lb: return 0
    
    # daca nu arunc: sa vedem cate pot sa produc
    bn, bt = Lb[0]
    ans1 = 0
    for i, (tn, tt) in enumerate(Lt):
        if tt == bt:
            prod = min(bn, tn)
            bnr = bn - prod
            tnr = tn - prod
            Lbr = Lb[1:]
            Ltr = Lt[i+1:]
            
            if bnr:
                Lbr = [(bnr, bt)] + Lbr

            if tnr:
                Ltr = [(tnr, bt)] + Ltr
            
            ans1 = prod + solve(Lbr, Ltr)
            break
    
    # daca le arunc: nu produc nimic, sa vedem ce iese la urmatoarea
    # pastrez jucariile, arunc doar cutiile
    ans2 = solve(Lb[1:], Lt)
    return max(ans1,ans2)
    

for k in range(T):
    
    N, M = readlist()
    Lb = readlist()
    Lt = readlist()
    LB = []
    LT = []
    for i in range(N):
        LB.append((Lb[2*i], Lb[2*i+1]))
    for i in range(M):
        LT.append((Lt[2*i], Lt[2*i+1]))
    
    #~ print LB
    #~ print LT
    
    ans = solve(LB, LT)
    print "Case #%d: %d" % ((k+1), ans)
    
    
