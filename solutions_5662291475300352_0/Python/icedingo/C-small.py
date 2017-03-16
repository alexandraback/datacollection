#!/usr/bin/env python3

T = int(input())

for t in range(T):
    N = int(input())
    hikers = []
    for n in range(N):
        D, H, M = map(int, input().split())
        for i in range(H):
            hikers.append((M+i, D))

    hikers.sort()

    fast = hikers[0]
    slow = hikers[1]

    slow_time = (360-slow[1])/360 * slow[0]
    fast_end = fast[1] + 360 * slow_time/fast[0]

    encounters = 0
    if fast_end >= 720:
        encounters = 1

    print('Case #{}: {}'.format(t+1, encounters))
