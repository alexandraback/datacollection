#!/usr/bin/env python3
# -*- coding: utf-8 -*-

T = int(input())

for t in range(1, T+1):
    extra = 0
    standing = 0

    s = [int(i) for i in input().split()[1]]

    for required, k in enumerate(s):
        if required > (extra + standing):
            extra = required - standing
        standing += k

    print("Case #{}:".format(t), extra)
