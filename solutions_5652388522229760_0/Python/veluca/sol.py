#!/usr/bin/env pypy3

import sys

def solve(n):
    seen = set()
    for i in range(1, 10000):
        for c in str(i*n):
            seen.add(c)
        if len(seen) == 10:
            return i*n
    return "INSOMNIA"

T = int(input())
cnt = 1
for l in sys.stdin:
    print("Case #%d:" % cnt, end=" ")
    cnt += 1
    print(solve(int(l.strip())))
