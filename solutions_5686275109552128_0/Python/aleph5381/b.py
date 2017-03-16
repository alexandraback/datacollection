#!/usr/bin/env python3

import sys
import copy
rl = lambda: sys.stdin.readline()
T = int(rl())

def time_brute_force(P):
    if len(P) == 0:
        return 0
    Pmax = max(P)
    if Pmax == 0:
        return 0
    if Pmax == 1:
        return 1
    # if it's a special minute
    # try all possible non-trivial splits
    ans1 = Pmax
    for j in range(2, Pmax//2+1):
        x = j
        y = Pmax - j
        P1 = copy.deepcopy(P)
        P1.remove(Pmax)
        P1.append(x)
        P1.append(y)
        ans1 = min(ans1, 1 + time_brute_force(P1))
    # if it's not a special minute
    P2 = [(x - 1) for x in P if (x - 1) > 0] # eat one and remove 0
    ans2 = 1 + time_brute_force(P2)
    #print("----")
    #print("P: ", P)
    #print("ans1:", ans1, "; ans2:", ans2, ";");
    ans = min(ans1, ans2)
    return ans

def solve(casei):
    D = int(rl())
    line = rl().split()
    P = []
    for i in range(0, len(line)):
        P.append(int(line[i]))
    ans = time_brute_force(P)
    print("Case #{}: {}".format(casei, ans))

for i in range(1, T+1):
    solve(i)
