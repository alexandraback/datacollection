#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def solve(P):
    k = 9

    while P[k] == 0 and k > 0:
        k -= 1
    if k <= 3:
        return k
    else:
        # backtracking
        # do all splits
        best_time = k

        P[k] -= 1
        for i in range(2, k//2 + 1):
            P[i] += 1
            P[k - i] += 1

            best_time = min(best_time, 1 + solve(P))

            P[i] -= 1
            P[k - i] -= 1
        P[k] += 1

        return best_time


T = int(input())

for t in range(1, T+1):
    D = int(input())
    P = [0] * 10

    for i in input().split():
        P[int(i)] += 1

    print("Case #{}:".format(t), solve(P))
