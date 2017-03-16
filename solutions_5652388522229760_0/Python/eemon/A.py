#!/usr/bin/env python
# -*- coding: utf-8 -*-

T = int(input())
for t in range(T):
    N = int(input())
    if N != 0:
        count = 1
        n = N * count
        nums = set(list(str(n)))

        while len(nums) < 10:
            count += 1
            n = N * count
            nums |= set(list(str(n)))
        print("Case #{0}: {1}".format(t+1, n))
    else:
        print("Case #{0}: {1}".format(t+1, "INSOMNIA"))

