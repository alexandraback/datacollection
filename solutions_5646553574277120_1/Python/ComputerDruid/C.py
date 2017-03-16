#!/usr/bin/env python3

def solve(C, denoms, V):
    denoms.append(V+1)
    count = 0
    idx = 0
    added = 0
    while idx < len(denoms):
        if count + 1 >= denoms[idx]:
            count += denoms[idx] * C
            idx += 1
        else:
            nextDenom = count + 1
            count += nextDenom * C
            added += 1
    return added

T = int(input())
for t in range(T):
    C, D, V = [int(x) for x in input().split(" ")]
    denominations = [int(x) for x in input().split(" ")]
    assert(len(denominations) == D)
    print("Case #" + str(t+1) +":", solve(C, denominations, V))
