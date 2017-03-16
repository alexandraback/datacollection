#! /usr/bin/env pypy
#
# difficult to explain here how I solved this,
# it has something to do with trees, combinatorics, ..
# --xykhl

import sys
from math import ceil

n = int(sys.stdin.readline().strip())

def ntreepos(n, comb):
    # comb should be an iterable of natural numbers
    if len(comb) > n:
        raise ValueError('too many coord items')
    pos = 0
    for i, x in enumerate(comb):
        pos = n * pos + (x-1)
    return pos+1

def mkcombs(n, k):
    x = 1
    a = []
    while 1:
        a.append(x)
        x += 1
        if len(a) == k or x > n:
            yield tuple(a)
            if x > n: break
            a = []

def solve(a):
    K, C, S = a
    k = min(K, C)
    ntestmin = int(ceil(1.0 * K / k))
    if S < ntestmin:
        return "IMPOSSIBLE"
    r = [ ntreepos(K, x) for x in mkcombs(K, k) ]
    return " ".join(str(x) for x in r)
    
for i in range(n):
    line = sys.stdin.readline().strip()
    a = [ int(x) for x in line.split(" ") ]
    r = solve(a)
    print("Case #{}: {}".format(i+1, r))

