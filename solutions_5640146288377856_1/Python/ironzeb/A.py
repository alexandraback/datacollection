#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function

if __name__ == '__main__':
    T = int(raw_input())

    for t in range(1, T + 1):
        R, C, W = map(int, raw_input().split())

        ans = R * (C / W)
        ans += W - 1
        if (C % W) > 0:
            ans += 1

        print("Case #{}: {}".format(t, ans))
