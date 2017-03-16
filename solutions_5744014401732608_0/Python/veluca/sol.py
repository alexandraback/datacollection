#!/usr/bin/env pypy3

import sys

def solve():
    B, M = map(int, input().split())
    if M > 2**(B-2):
        return "IMPOSSIBLE"
    sol = [['0' for i in range(B)] for i in range(B)]
    for i in range(B-1):
        for j in range(0, i):
            sol[j][i] = '1'
    if M == 2**(B-2):
        sol[0][B-1] = '1'
        M -= 1
    for i in range(B-2):
        if M & (2**i):
            sol[1+i][B-1] = '1'
    return "POSSIBLE\n" + "\n".join("".join(sol[i]) for i in range(B))

T = int(input())
for l in range(1, T+1):
    print("Case #%d:" % l, end=" ")
    print(solve())
