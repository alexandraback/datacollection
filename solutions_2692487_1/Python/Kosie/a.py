#!/usr/bin/env python3

import sys
sys.setrecursionlimit(10000)

T = int(input())

def solve(A, other_motes):
    if not other_motes:
        return 0;
    #print(A, other_motes)

    ans = len(other_motes)

    to_add = 0
    t_A = A
    prefix = []

    while t_A <= other_motes[0]:
        if to_add > ans:
            return ans;
        to_add += 1
        prefix.append(t_A - 1)
        t_A += t_A - 1

    #print(prefix)

    other_motes = prefix + other_motes
    while other_motes and other_motes[0] < A:
        A += other_motes[0]
        other_motes = other_motes[1:]
    t_ans = to_add + solve(A, other_motes)

    return min(ans, t_ans)

for case in range(1, T+1):
    A, N = map(int, input().split())
    other_motes = list(map(int, input().split()))
    other_motes.sort()

    ans = solve(A, other_motes)

    print("Case #{}: {}".format(case, ans))
