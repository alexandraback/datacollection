#!/usr/bin/env python3
import random

def gen(n):
    lim = 1000
    b = "1" + "".join(random.choice("01") for _ in range(n-2)) + "1"
    r = []
    for i in range(2, 11):
        s = int(b, i)
        for j in range(2, min(lim, s)):
            if s % j == 0:
                r.append(j)
                break
        else:
            return b, None
    return b, r

n = int(input())
assert n == 1
n, j = map(int, input().split())
print("Case #1:")
seen = {}
while len(seen) < j:
    b, v = gen(n)
    if v:
        seen[b] = v

for k, v in seen.items():
    print(k + " " + " ".join(map(str, v)))

