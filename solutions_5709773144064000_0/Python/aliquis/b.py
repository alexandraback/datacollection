#!/usr/bin/env python
def solve(c, f, x):
    cost = 0
    total = 1e100
    j = 0
    while True:
        curr = cost + x/(2 + j*f)
        if total < curr:
            return total
        total = curr
        cost = cost + c/(2 + j*f)
        j = j + 1

[cases] = map(int, input().split())
for i in range(0, cases):
    [c, f, x] = map(float, input().split())
    print("Case #{0}: {1:.7f}".format(i+1, solve(c, f, x)))
