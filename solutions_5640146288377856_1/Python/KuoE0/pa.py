#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2015 KuoE0 <kuoe0.tw@gmail.com>
#
# Distributed under terms of the MIT license.

"""

"""

T = input()

for t in range(T):
    R, C, W = [int(x) for x in raw_input().split()]

    ret = 0
    least = C / W - 1
    remain = C - W * least

    if remain != W:
        # if remain % 2 == 1:
        #     hit = 1
        #     miss = 1
        #     ret = least + hit + miss + (W - hit)
        # else:
        #     hit = 2
        #     miss = 1
        #     ret = least + hit + miss + (W - hit)
        ret = least + W + 1
    else:
        ret = least + W

    ret = ret + (C / W) * (R - 1)

    print "Case #{0}: {1}".format(t + 1, ret)


