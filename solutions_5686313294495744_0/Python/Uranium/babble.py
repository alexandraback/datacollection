#!/usr/bin/env python2

import itertools

def match(needle, haystack, i):
    for k in haystack:
        if k[i] == needle:
            return True
    return False

def solve(W):
    max_fake = 0

    for R in itertools.product([True, False], repeat=len(W)):
        real = []
        i = 0
        for v in R:
            if v:
                real.append(W[i])
            i += 1

        pot_fake = []
        i = 0
        for v in R:
            if not v:
                pot_fake.append(W[i])
            i += 1

        tot_fake = 0
        for f in pot_fake:
            if match(f[0], real, 0) and match(f[1], real, 1):
                tot_fake += 1

        if tot_fake > max_fake:
            max_fake = tot_fake

    return max_fake


T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    W = []
    for j in xrange(N):
        a, b = raw_input().strip().split()
        W.append((a, b))
    print "Case #%s: %s" % (i, solve(W))
