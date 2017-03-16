'''
Created on 08 de mayo de 2016

@author: Marcelo
'''
from Queue import Empty
from __builtin__ import str
def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def isRepetead(L, P):
    if P in L:
        return True
    else:
        return False
def doubleRepeted(K, L, P):
    jp = 0
    js = 0
    ps = 0

    for y in L:
        if P[0] == y[0] and P[1] == y[1]:
            jp += 1
            if jp >= K:
                return True
        if P[0] == y[0] and P[2] == y[2]:
            js += 1
            if js >= K:
                return True
        if P[1] == y[1] and P[2] == y[2]:
            ps += 1   
            if ps >= K:
                return True
    return False

def solve(J, P, S, K):
    ap = []
    r = []
    for j in range(J):
        for p in range(P):
            for s in range(S):
                ap.append([j+1, p+1, s+1])
    for y in ap:
        if isRepetead(r, y) == False and doubleRepeted(K, r, y) == False:
            r.append(y)
        
    return r


_T = readint()
for t in range(1, _T+1):

    P = [int(x) for x in raw_input().split(" ")]
    r = solve(P[0], P[1], P[2], P[3])

    print 'Case #%i:'%(t), len(r)
    for rr in r:
        print ' '.join([str(x) for x in rr])