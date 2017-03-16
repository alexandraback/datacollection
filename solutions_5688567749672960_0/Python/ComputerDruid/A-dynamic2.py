#!/usr/bin/env python3

def solve(N):
    dyn = [float("inf")] * (N + 1)
    dyn[1] = 1
    for num in range(1, N+1):
        cost = dyn[num]
        choices = [num+1, int(str(num)[::-1])]
        for place in choices:
            if place <= N:
                dyn[place] = min(dyn[place], cost + 1)
    return dyn[N]

T = int(input())
for t in range(T):
    N = int(input())
    print("Case #" + str(t+1) +":", solve(N))
