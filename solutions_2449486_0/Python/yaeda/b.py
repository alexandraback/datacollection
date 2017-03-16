#!/bin/python
# -*- coding: utf-8 -*-

import sys

def flatten(l):
    if isinstance(l, list):
        if l == []:
            return []
        else:
            return flatten(l[0]) + flatten(l[1:])
    else:
        return [l]

def check(case, a, b):
    flag = [[0 for x in range(0, b)] for y in range(0, a)]
    # row
    for y in range(0, a):
        row = case[y]
        value = max(row)
        for i in range(0, b):
            if row[i] == value:
                flag[y][i] = 1
    # col
    for x in range(0, b):
        col = []
        for i in range(0, a):
            col.append(case[i][x])
        value = max(col)
        for i in range(0, a):
            if col[i] == value:
                flag[i][x] = 1
    return 'YES' if len(set(flatten(flag))) == 1 else 'NO'

if __name__ == '__main__':
    lines = sys.stdin.readlines()
    n = int(lines[0][:-1])
    pos = 1;
    for i in range(0, n):
        a, b = [int(x) for x in lines[pos][:-1].split(' ')]
        case = []
        for j in range(0, a):
            case.append([int(x) for x in lines[pos + 1 + j][:-1].split(' ')])
        result = check(case, a, b)
        print 'Case #%d: %s' % (i+1, result)
        pos += int(a) + 1
