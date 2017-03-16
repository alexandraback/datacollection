#!/usr/bin/env python3

import itertools


def solve(K, C, S):
    if C * S < K:
        return None
    res = []
    pos = 0
    for i in range(1, S + 1):
        t = 1
        for p in range(C):
            if pos >= K:
                break
            t += pos * K ** (C - 1 - p)
            pos += 1
        res.append(t)
        if K <= i * C:
            break
    return res


T = int(input())
for t in range(1, T + 1):
    K, C, S = map(int, input().split())
    ans = solve(K, C, S)
    if ans is None:
        print("Case #{}: IMPOSSIBLE".format(t))
    else:
        print("Case #{}: {}".format(t, " ".join(str(a)for a in ans)))
