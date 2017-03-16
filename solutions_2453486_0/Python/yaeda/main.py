#!/bin/python
# -*- coding: utf-8 -*-

import sys
import random
import math

n = 0
cases = []

def check4(line):
    sum = 0
    for i in range(0, 4):
        if line[i] == '.':
            return 0
        elif line[i] == 'X':
            sum += 1
        elif line[i] == 'O':
            sum -= 1
    if sum >= 3:
        return 1
    if sum <= -3:
        return -1
    return -2

def check(case):
    o = x = e = 0
    for r in range(0, 4):
        val = check4(case[r * 4: r * 4 + 4])
        if val == 1:
            x = 1
        if val == -1:
            o = 1
        if val == 0:
            e = 1
    for c in range(0, 4):
        val = check4(case[c] + case[c + 4] + case[c + 8] + case[c + 12])
        if val == 1:
            x = 1
        if val == -1:
            o = 1
        if val == 0:
            e = 1
    val = check4(case[0] + case[5] + case[10] + case[15])
    if val == 1:
        x = 1
    if val == -1:
        o = 1
    if val == 0:
        e = 1
    val = check4(case[3] + case[6] + case[9] + case[12])
    if val == 1:
        x = 1
    if val == -1:
        o = 1
    if val == 0:
        e = 1
    if x == 1 and o == 0:
        return 'X won'
    if x == 0 and o == 1:
        return 'O won'
    if x == 1 and o == 1:
        return 'Draw'        
    if x == 0 and o == 0 and e == 0:
        return 'Draw'        
    if x == 0 and o == 0 and e == 1:
        return 'Game has not completed'        
        
if __name__ == '__main__':
    lines = sys.stdin.readlines()
    n = int(lines[0][:-1])
    for i in range(0, n):
        case = lines[5 * i + 1][:-1] + lines[5 * i + 2][:-1] + lines[5 * i + 3][:-1] + lines[5 * i + 4][:-1]
        result = check(case)
        print 'Case #%d: %s' % (i+1, result)
