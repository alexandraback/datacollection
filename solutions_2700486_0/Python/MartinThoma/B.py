#!/usr/bin/env python
# -*- coding: utf-8 -*-

import gmpy

def binomial(n, k):
    return gmpy.comb(n,k)

def solve(N, x, y):
    if x == 0:
        n = y+1
        if N >= (n*n+n)/2:
            return 1.0
        else:
            return 0.0

    xTmp = x + y # let target slide down
    n = xTmp-1
    baseDiamands = (n*n+n)/2
    rest = N - baseDiamands
    if rest <= 0:
        return 0.0

    # bernoulli
    prob = 0.0
    trefferNeeded = y+1

    for k in range(trefferNeeded, rest+1):
        prob += binomial(rest,k)
    
    return prob/2**rest
 
if __name__ == "__main__":
    testcases = input()
      
    for caseNr in xrange(1, testcases+1):
        N, x, y = map(int,raw_input().split(" "))
        sol = str(solve(N, abs(x), y))
        if len(sol) > 9:
            sol = sol[0:9]
        print("Case #%i: %s" % (caseNr, sol))
