#!/usr/bin/env python

import math
import sys

def factor(x):
    if x == 1:
        return []
    if x % 2 == 0:
        return [2] + factor(x/2)
    k = 3
    while k < math.sqrt(x) + 1:
        if x % k == 0:
            return [k] + factor(x/k)
        k += 2
    return [x]

def numbits(x):
    k = 0
    while (x >> k): k += 1
    return k

def guess(prodlist, n):
    prodlist = sorted(prodlist)[::-1]
    factorlist = factor(prodlist[0])
    for p in prodlist[1:]:
        for f in factor(p):
            if f not in factorlist:
                factorlist.append(f)
                factorlist = sorted(factorlist)
    while(len(factorlist) > n):
        factorlist = factorlist[2:] + [factorlist[0]*factorlist[1]]
    if len(factorlist) < n:
        factorlist = factorlist + [2] * (n - len(factorlist))
    return ''.join(map(str,factorlist))

sys.stdin.readline()
print "Case #1:"
(R, N, M, K) = map(int, sys.stdin.readline().split(" "))
for case in range(0,R):
    prodlist = map(int, sys.stdin.readline().split(" "))
    print guess(prodlist, N)
