#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function


def max_occurences(S, L, keys, target):
    if any((t not in keys for t in target)):
        return 0

    overlap = 0  # overlap between start and end of target string
    for i in range(1, len(target)):
        if target[0:i] == target[-i:] and i > overlap:
            overlap = i
    starts_every = L - overlap
    c = 0
    i = L - 1
    while i < S:
        c += 1
        i += starts_every
    return c


if __name__ == '__main__':
    T = int(raw_input())

    for t in range(1, T + 1):
        K, L, S = map(int, raw_input().split())

        keys = raw_input().strip()
        target = raw_input().strip()

        occ = max_occurences(S, L, keys, target)
        if occ == 0:
            print("Case #{}: {}".format(t, 0.0))
            continue

        d = {}
        for k in keys:
            if not d.get(k):
                d[k] = 0
            d[k] += 1

        for k, v in d.items():
            d[k] = v * 1.0 / K

        prob = 1.0
        for ta in target:
            prob *= d[ta]
        prob *= occ

        print("Case #{}: {}".format(t, occ - prob))
