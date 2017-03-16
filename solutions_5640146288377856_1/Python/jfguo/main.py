
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
    s = get_line().split()
    R, C, W = int(s[0]), int(s[1]), int(s[2])

    ans = 0
    while 2*W < C:
        ans += 1
        C -= W
    ans += W
    if C > W:
        ans += 1
    return ans*R

T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
