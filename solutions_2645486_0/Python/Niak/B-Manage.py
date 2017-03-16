#!/usr/bin/env python

import sys

E,R,N = 0,0,0
v = []
D = {}

# gain max apres i taches en terminant avec e joules
def G(i,e):
    global D
    if i<0:
        return 0
    if e<0 or e>E:
        print >> sys.stderr, 'GRRR'
        sys.exit(1)
    if (i,e) in D:
        return D[(i,e)]
    res = 0
    for initE in range(max(e,R),E+1):
        res = max(res,G(i-1,initE-R)+v[i]*(initE-e))
    D[(i,e)] = res
    return res

def main():
    global E,R,N,v,D
    f = open(sys.argv[1],'r')
    T = int(f.readline())
    for t in range(1,T+1):
        D = {}
        E,R,N = tuple(map(int,f.readline().split()))
        v = map(int,f.readline().split())
        print 'Case #%d: %d' % (t,G(N-1,0))

main()
