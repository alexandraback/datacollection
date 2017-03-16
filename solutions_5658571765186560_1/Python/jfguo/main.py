
import os
import sys
import glob
import subprocess
import random
import fileinput


next_line = 0
lines = [line.strip() for line in fileinput.input()]
def get_line():
    global next_line
    i = next_line
    next_line += 1
    return lines[i]


def calc():
    s = get_line().split(' ')
    X = int(s[0])
    R = int(s[1])
    C = int(s[2])
    if R > C:
        R, C = C, R

    if R*C % X != 0:
        return 'RICHARD'
    if R < (X + 1)/2:
        return 'RICHARD'

    if X == 1:
        return 'GABRIEL'
    if X == 2:
        return 'GABRIEL'
    if X == 3:
        return 'GABRIEL'
    if X == 4:
        if R == 2:
            return 'RICHARD'
        if R == 3:
            return 'GABRIEL'
        if R == 4:
            return 'GABRIEL'
    if X >= 7:
        return 'RICHARD'

    if R >= (X + 1)/2 + 1:
        return 'GABRIEL'

    if R*C <= 2*X:
        return 'RICHARD'
    return 'GABRIEL'


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
