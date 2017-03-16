#!/usr/bin/env python3

def solve(N):
    if N == 0: return "INSOMNIA"
    c = N
    D = set()
    for i in range(1000):
        D |= set(str(c))
        if len(D) == 10: return c
        c += N
    raise "WE PLAYED AND LOST"

tests = int(input())
for test in range(tests):
    N = int(input())
    result = solve(N)
    print("Case #{}: {}".format(1+test, result))
