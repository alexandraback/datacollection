#!/usr/bin/env python3

cases = int(input())

database = [{}, {}, {}]

def fashion_jail(j, p, s, k):
    sets = [(j,p), (j,s), (p,s)]
    used = [0, 0, 0]
    for i in range(3):
        used[i] = database[i].get(sets[i], 0) + 1
        if used[i] > k:
            return True
    for i in range(3):
        database[i][sets[i]] = used[i]
    return False

for T in range(1, cases+1):
    J, P, S, K = [int(x) for x in input().split()]
    combinations = reversed([(j, p, s) for j in range(J) for p in range(P) for s in range(S)])

    database = [{}, {}, {}]
    combinations = [(j, p, s) for j, p, s in combinations if not fashion_jail(j, p, s, K)]

    max_days = len(combinations)
    print("Case #{}: {}".format(T, max_days))
    for c in combinations:
        j, p, s = c
        print("{} {} {}".format(j+1, p+1, s+1))

