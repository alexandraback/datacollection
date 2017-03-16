#!/usr/bin/env python3

# Google Code Jam 2012, Round 1B, Problem C: Equal Sums

import itertools

cases = int(input())
for case in range(cases):
    inp = list(int(s) for s in input().split())
    N = inp[0]
    S = inp[1:]
    d = {}
    found = False
    for l in range(1, N-1):
        for c in itertools.combinations(S, l):
            s = sum(c)
            if s in d:
                f1, f2 = d[s], c
                found = True
                break
            d[s] = c
        if found:
            break
    print("Case #{}:".format(case+1))
    if found:
        print(" ".join(str(f) for f in f1))
        print(" ".join(str(f) for f in f2))
    else:
        print("Impossible")
