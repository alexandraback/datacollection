
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


def can_chase(d0, m0, d1, m1):
    #print d0, m0, d1, m1
    return d0*m0 + (360-d1)*m1 <= (m0-m1)*360


def calc():
    N = int(get_line())
    hikers = []
    for i in range(N):
        s = get_line().split()
        D, H, M = int(s[0]), int(s[1]), int(s[2])
        for j in range(H):
            hikers.append((M + j, D))
    hikers.sort()

    ans = 0
    for i in range(len(hikers) - 1, 0, -1):
        is_chased = False
        for j in range(0, i):
            if can_chase(hikers[i][1], hikers[i][0], hikers[j][1], hikers[j][0]):
                is_chased = True
                break
        if is_chased:
            ans += 1
    return ans


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
