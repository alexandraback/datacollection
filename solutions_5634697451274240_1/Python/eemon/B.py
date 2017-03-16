#!/usr/bin/env python
# -*- coding: utf-8 -*-

T = int(input())

for t in range(T):
    S = list(input())
    N = len(S)
    count = 0

    current = S[0]
    idx = 1

    while idx < N:
        if current != S[idx]:
            count += 1
            current = S[idx]
        idx += 1
    if current == '-':
        count += 1

    print("Case #{0}: {1}".format(t+1, count))
