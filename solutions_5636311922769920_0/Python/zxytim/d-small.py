#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: d-small.py
# $Date: Sat Apr 09 22:55:03 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>


def solve():
    K, C, S = map(int, input().strip().split())
    assert S == K, (S, K)
    n = K**C
    return(' '.join(map(str, [i * K**(C-1) + 1 for i in range(K)])))

nr_case = int(input().strip())

for caseid in range(1, nr_case + 1):
    print('Case #{}: {}'.format(caseid, solve()))


# vim: foldmethod=marker

