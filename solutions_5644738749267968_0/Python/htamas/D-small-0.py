#!/usr/bin/env python3

from itertools import accumulate

T = int(input())
for case in range(1, T+1):
    N = int(input())
    b = [(float(i), -1) for i in input().split()]
    b += [(float(i), 1) for i in input().split()]
    h = list(accumulate(list(zip(*sorted(b)))[1]))
    print("Case #{}: {} {}".format(case, N+min(h), max(h)))

