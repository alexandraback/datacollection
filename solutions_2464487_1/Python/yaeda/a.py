#!/bin/python
# -*- coding: utf-8 -*-

import sys
import random
import math


def solve(r, t):
    cand = math.floor((math.sqrt((2.0 * r - 1) * (2.0 * r - 1) + 8.0 * t) - (2.0 * r - 1.0)) / 4.0)
    if (2 * cand * cand + (2 * r - 1) * cand > t):
        cand -= 1
    return cand
        
if __name__ == '__main__':
    lines = sys.stdin.readlines()
    T = int(lines[0][:-1])
    for i in range(0, T):
        r, t = [int(x) for x in lines[i + 1][:-1].split(' ')]
        result = solve(r, t)
        print 'Case #%d: %d' % ((i + 1), result)



