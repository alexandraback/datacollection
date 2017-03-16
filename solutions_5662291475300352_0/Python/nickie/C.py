#!/usr/bin/env python3

from fractions import Fraction as F

def solve(N, L):
    if len(L) < 2: return 0
    if len(L) > 2: return # only first small
    L.sort(key=lambda p: (p[1], p[0]), reverse=True)
    d1, s1 = L[0]
    t = F(360-d1, s1) # when the slow one will reach the finish line
    d2, s2 = L[1]
    # print(d1, s1, d2, s2, t, d2 + s2 * t, d2 + s2 * t >= 720)
    if d2 + s2 * t >= 720:
        return 1
    else:
        return 0

tests = int(input())
for test in range(tests):
    N = int(input())
    L = []
    for i in range(N):
        D, H, M = map(int, input().split())
        for j in range(H):
            L.append((D, M+j))
    result = solve(N, L)
    print("Case #{}: {}".format(1+test, result))
