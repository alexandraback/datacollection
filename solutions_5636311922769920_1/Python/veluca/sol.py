#!/usr/bin/env pypy3

import sys

def solve(K, C, S):
    if S*C < K:
        return None
    res = []
    for p in range(0, K, C):
        tile = 0
        power = 1
        for i in range(p, min(p+C, K)):
            tile += power*i
            power *= K
        res.append(tile) 
    return res

T = int(input())
cnt = 1
for l in sys.stdin:
    print("Case #%d:" % cnt, end=" ")
    cnt += 1
    result = solve(*list(map(int, l.split())))
    if result is None:
        print("IMPOSSIBLE")
    else:
        print(" ".join(str(x+1) for x in result))
