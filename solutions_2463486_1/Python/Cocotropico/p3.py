#!/usr/bin/env python3

import math

Ncases = int(input())

def ispal(x):
    s = repr(x)
    return s == s[::-1]

def nextpal(x):
    s = list(repr(x))
    l = len(s)
    m = l // 2

    if not ispal(x):
        for i in range(m):
            s[l - 1 - i] = s[i]
        y = int(''.join(s), 10)
        if y > x:
            return y
        else:
            return nextpal(y)

    oldc = int(s[m], 10)
    if oldc < 9:
        s[m] = s[l - 1 - m] = str(oldc + 1)
        return int(''.join(s), 10)

    if (l % 2) == 0:
        m = m - 1
    while m >= 0:
        oldc = int(s[m], 10)
        if oldc < 9:
            s[m] = s[l - 1 - m] = str(oldc + 1)
            return int(''.join(s), 10)
        else:
            s[m] = s[l - 1 - m] = '0'
            m = m - 1
    return int('1' + ('0' * (len(s) - 1)) + '1', 10)

def solve(icase, I1, I2):
    count = 0

    I = 0
    if not ispal(I):
        I = nextpal(I)

    maj = 30001 + I2 / 100000
    while I <= maj:
        Isq = I * I
        if Isq >= I1 and Isq <= I2 and ispal(Isq):
            count = count + 1
        I = nextpal(I)

    print('Case #%d: %d' % (icase, count))

for icase in range(Ncases):
    I1, I2 = [int(x) for x in input().split(' ')]
    solve(icase + 1, I1, I2)
