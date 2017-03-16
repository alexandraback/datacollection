#!/usr/bin/env python
# encoding: utf-8
"""
problem4.py

Created by Darcy on 09/04/2016.
Copyright (c) 2016 Darcy. All rights reserved.
"""

import sys
import os
import time


def solve():
    for tc in range(input()):
        K, C,  S = raw_input().split(' ')
        k = int(K)
        c = int(C)
        s = int(S)

        # print K, C, S
        print 'Case #%d: ' % (tc+1, ) ,

        sequence = list(range(0, k))
        positions = []
        while len(sequence) > 0:
            indexes = sequence[:c]
            del sequence[:c]
            if len(indexes) < c:
                indexes += [0]* (c-len(indexes))

            index = 0
            for i, d in enumerate(indexes):
                index += d * (k ** i)
            positions.append(index)
        if len(positions) > s:
            print 'IMPOSSIBLE'
        else:
            # positions.sort()
            for p in positions:
                print p+1,
            print


def main():
    # fsock = open('input4.txt', 'r')
    # sys.stdin = fsock
    solve()
    # fsock.close()


if '__main__' == __name__:
    main()
