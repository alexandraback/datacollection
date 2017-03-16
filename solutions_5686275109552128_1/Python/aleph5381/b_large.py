#!/usr/bin/env python3

import sys
import copy
import math

rl = lambda: sys.stdin.readline()
T = int(rl())

def time(P):
    if len(P) == 0:
        return 0
    Pmax = max(P)
    ans = Pmax
    for i in range(1, Pmax+1):
        # split all dishes downto <=i pancakes
        time = i
        for j in range(0, len(P)):
            special = (P[j] // i) - 1
            if (P[j] % i) > 0:
                special += 1
            time += special
        ans = min(ans, time)
    return ans

def solve(casei):
    D = int(rl())
    line = rl().split()
    P = []
    for i in range(0, len(line)):
        P.append(int(line[i]))
    ans = time(P)
    print("Case #{}: {}".format(casei, ans))

for i in range(1, T+1):
    solve(i)
