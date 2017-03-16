# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys
import numpy as np

def solve_case(string):
    d = {}
    for c in "ZONETWHRFUIVSXNG":
        d[c] = 0
    for c in string:
        d[c] = d.get(c, 0) + 1
    ans = {}
    for digit in range(10):
        ans[digit] = 0
    ans[0] = d['Z']
    for x in 'ZERO':
        d[x] -= ans[0]
    ans[2] = d['W']
    for x in 'TWO':
        d[x] -= ans[2]
    ans[4] = d['U']
    for x in 'FOUR':
        d[x] -= ans[4]
    ans[6] = d['X']
    for x in 'SIX':
        d[x] -= ans[6]
    ans[8] = d['G']
    for x in 'EIGHT':
        d[x] -= ans[8]
    ans[3] = d['H']
    for x in 'THREE':
        d[x] -= ans[3]
    ans[1] = d['O']
    for x in 'ONE':
        d[x] -= ans[1]
    ans[5] = d['F']
    for x in 'FIVE':
        d[x] -= ans[5]
    ans[7] = d['V']
    for x in 'SEVEN':
        d[x] -= ans[7]
    ans[9] = d['I']
    ret = ""
    for digit in range(10):
        if ans[digit] > 0:
            ret += "{0}".format(digit) * ans[digit]
    return ret
    

num_cases = int(sys.stdin.readline())
for n in range(1, num_cases + 1):
    case  = sys.stdin.readline()
    print("Case #{0}: {1}".format(n, solve_case(case)) )
