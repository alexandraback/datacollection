#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser


def solve(s):
    moves = 0

    for i in range(len(s)):
        happy = s[i]
        if i == 0:
            if not happy:
                moves += 1
        else:
            prev_happy = s[i-1]
            if not happy and prev_happy:
                moves += 2

    return moves


inputfile = FileParser()
T = inputfile.read_int()
for test in range(1, T+1):
    # the stack, top (0) to bottom (len-1)
    s = inputfile.read_string()
    p = [ c == "+" for c in s ]

    result = solve(p)

    print "Case #{}: {}".format(test, result)
