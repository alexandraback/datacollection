#! /#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

fh = open(sys.argv[1], 'r')
T = int(fh.readline())  # number of test cases
for t in range(T):
    S = fh.readline().split()[0]  # string of letters
    res = ''
    oldval = -1
    for c in S:
        val = ord(c)
        if val >= oldval:
            res = c + res
            oldval = ord(c)
        else:
            res = res + c
    print('Case #{:d}: {}'.format(t + 1, res))
