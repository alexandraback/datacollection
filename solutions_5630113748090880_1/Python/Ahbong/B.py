#!/usr/bin/env python3


import collections
import itertools


def solos(iterable):
    counter = collections.Counter(iterable)
    res = []
    for key, value in counter.items():
        if value % 2 == 1:
            res.append(key)
    return res


def solve(slists):
    return sorted(solos(itertools.chain.from_iterable(slists)))


T = int(input())
for t in range(1, T + 1):
    N = int(input())
    slists = []
    for _ in range(2 * N - 1):
        slists.append(list(map(int, input().split())))
    ans = solve(slists)
    print("Case #{}: {}".format(t, " ".join(map(str, ans))))
