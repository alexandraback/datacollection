#!/usr/bin/env python3

def solve(N):
    seen = set()
    cur = 0
    for i in range(100):
        cur += N
        seen.update(str(cur))
        if len(seen) == 10:
            return cur
    else:
        return "INSOMNIA"

T = int(input())
for t in range(1, T + 1):
    N = int(input())
    ans = solve(N)
    print("Case #{}: {}".format(t, ans))
