#!/usr/bin/env python3
# -*- coding: utf-8 -*-

T = int(input())

for t in range(1, T+1):
    x, r, c = [int(i) for i in input().split()]
    if (x == 1  # trivial
            or (x == 2 and (r * c) % 2 == 0)
            ):
        print("Case #{}:".format(t), 'GABRIEL')
    elif ((r * c) % x != 0        # trivial
            or x >= 7           # chose second of samples given in problem discription
            or x > max(r, c)    # Xx1
            or x > r + c - 1    # T-shape does not fit
            or (x == r + c - 1 and r != 1 and c != 1) # T-shape can cut of min(r, c) - 1 < r + c - 1
            or (x == r + c - 1 and (r == 1 or c == 1)) # T-shape does not fit since x >= 3
            ):
        print("Case #{}:".format(t), 'RICHARD')
    # Special cases for 4 and 6 (short T-shape)
    # Note: does not happen for x == 5 (and cross or t-shape)
    elif ((x == 4 and min(r, c) == 2)    # remaining left and right are odd
            or (x == 6 and min(r, c) == 3) # remaining are 1 or 2 mod 3
            ):
        print("Case #{}:".format(t), 'RICHARD')

    else:       #
        # 3 <= x <= 6 and the peace can be placed that it touches only one side
        # (no small regions are cut off)
        print("Case #{}:".format(t), 'GABRIEL')  # possible
