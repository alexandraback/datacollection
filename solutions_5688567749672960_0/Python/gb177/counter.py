#!/usr/bin/python

#
# O(n^2) for small case (should finish!?)
#
from itertools import product

def N(): return tuple(map(int, raw_input().split()))

def rev(v):
    return int(str(v)[::-1])

L = 10**6
M = [L+1] * (L+1)

M[1] = 1
for i in range(1, L):
    M[i+1] = min(M[i+1], M[i] + 1)
    ir = rev(i)
    if 1 <= ir <= L:
        M[ir] = min(M[ir], M[i] + 1)

T = N()[0]
for t in range(1, T + 1):
    n = N()[0]
    answer = M[n]
    
    print "Case #%d: %s" % (t, answer)

