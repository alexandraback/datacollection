import sys
from collections import defaultdict
from fractions import gcd
from math import factorial

T = int(sys.stdin.readline())

ab, bc, ac = defaultdict(int), defaultdict(int), defaultdict(int)

def check_it(sol, s, K):
    if ab[(sol[0], sol[1])] >= K:
        return False
    if bc[(sol[1], sol[2])] >= K:
        return False
    if ac[(sol[0], sol[2])] >= K:
        return False
    if sol in s:
        return False
    ab[(sol[0], sol[1])] += 1
    bc[(sol[1], sol[2])] += 1
    ac[(sol[0], sol[2])] += 1
    s.add(sol)
    return True
    
case = 1
for case in range(1, T+1):
    A,B,C,K = map(int, sys.stdin.readline().strip().split())
    ab, bc, ac = defaultdict(int), defaultdict(int), defaultdict(int)
    sol = (0,0,0)
    s = set([])
    check_it(sol, s, K)
    sol = (A-1,B-1,C-1)
    check_it(sol, s, K)
    
    for i in range(A):
        for j in range(B):
            for k in range(C):
                sol = (i,j,k)
                check_it(sol, s, K)
    print "Case #{0}:".format(case), len(s)
    for i in s:
        print i[0] + 1, i[1] + 1, i[2] + 1
        
#print sums
