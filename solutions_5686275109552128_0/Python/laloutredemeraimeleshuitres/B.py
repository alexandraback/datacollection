import itertools
import math
import collections
def solve_case(D, P):
    T = collections.defaultdict(int)
    for k,g in itertools.groupby(sorted(P)):
        T[k] = len(list(g))
    P = T
    cut = 0
    while True:
        k = max(P)
        l = P[k]
        c = int(math.sqrt(1.0*k/l))
        if c < 2:
            break
        P.pop(k)
        a = k // c
        P[a] += l*(c - (k % c))
        if k % c:
            P[a+1] += l*(k % c)
        cut += l*(c-1)
    return cut + max(P)
    
def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1),
        D = int(f.readline())
        print solve_case(D, map(int, f.readline().split()))

import sys
parse(sys.stdin)
