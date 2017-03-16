#! /#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import sys

fh = open(sys.argv[1], 'r')
T = int(fh.readline())  # number of test cases
for t in range(T):
    N = int(fh.readline())  # number of rows or columns
    grid = [[0] * N for n in range(N)]  # empty grid
    rows = [False] * N  # used rows
    cols = [False] * N  # used columns
    allnum = list()
    for i in range(2 * N - 1):
        val = [int(h) for h in fh.readline().split()]
        for v in val:
            allnum.append(v)

    # Find odd occcurrences
    count = np.bincount(allnum)
    res = list()
    for i in range(count.shape[0]):
        if count[i] % 2 == 1:
            res.append(str(i))
    res = ' '.join(res)

    print('Case #{:d}: {}'.format(t + 1, res))
