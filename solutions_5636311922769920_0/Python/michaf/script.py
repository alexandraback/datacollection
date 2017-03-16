#!/usr/bin/env python3

import sys, os, re
import collections
import math
sys.setrecursionlimit(200)

def debug(x):
    print(x, file=sys.stderr) 

def solve_small(K, C, S):
    ans = range(1, K+1)
    return " ".join([str(x) for x in ans])


def solve(K, C, S):
    ans = []
    k_seen = 0
    for s in range(S):
        x = 0
        for layer in range(C):
            if x + k_seen * K**layer < K**C:
                x += k_seen * K**layer
                k_seen += 1
        if str(x+1) not in ans:
            ans.append(str(x + 1))
    return " ".join(ans)


def main():
    inp = [x.strip() for x in sys.stdin.readlines()]
    T, D_raw = int(inp[0]), inp[1:]
    D = [[int(y) for y in x.split(" ")] for x in D_raw]

    debug(T)
    debug(D)

    for numinput, d in enumerate(D, 1):
        K, C, S = d
        debug("%d %d %d" % (K, C, S))
        #if S == K:
        #    ans = solve_small(K, C, S)
        if K > S * C:
            ans = "IMPOSSIBLE"
        else:
            ans = solve(K, C, S)
        print("Case #%d: %s" % (numinput, ans))

if __name__ == '__main__':
    main()
