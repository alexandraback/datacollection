#!/usr/bin/env python3

def solve(P):
    res = 0
    for l, r in zip(P, P[1:]):
        if l != r:
            res += 1
    if P[-1] == '-':
        res += 1
    return res

T = int(input())
for t in range(1, T + 1):
    P = input()
    ans = solve(P)
    print("Case #{}: {}".format(t, ans))
