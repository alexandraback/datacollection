#! /#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import sys

fh = open(sys.argv[1], 'r')
T = int(fh.readline())  # number of test cases
for t in range(T):
    B, M = [int(v) for v in fh.readline().split()]  # buildings and ways

    maxways = 2**(B - 2)
    # print B, M, maxways
    if M > maxways:
        res = 'IMPOSSIBLE'
    else:
        mat = np.zeros((B, B))
        # connect as binary number
        for i in range(B):
            for j in range(i + 1, B - 1):
                mat[i, j] = 1
        # choose the outputs
        if M == maxways:
            # connect all
            for i in range(B - 1):
                mat[i, -1] = 1
        elif M == 1:
            mat[0, -1] = 1
        else:
            # connect the appropiate ones
            n = bin(M)[2:]
            n = '0' * ((B - 2) - len(n)) + n  # length B - 2
            # print M, n
            n = n[::-1]
            for i in range(1, B - 1):
                c = n[i - 1]
                mat[i, -1] = int(c)

        # result
        res = ['POSSIBLE']
        for i in range(B):
            res.append(''.join([str(int(v)) for v in mat[i, :]]))
        res = '\n'.join(res)
        #print mat



    print('Case #{:d}: {}'.format(t + 1, res))
