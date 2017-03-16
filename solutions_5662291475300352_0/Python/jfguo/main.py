
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
    N = int(get_line())
    hikers = []
    for i in range(N):
        s = get_line().split()
        D, H, M = int(s[0]), int(s[1]), int(s[2])
        for j in range(H):
            hikers.append((D, M + j))
    hikers.sort()

    if len(hikers) <= 1:
        return 0
    if len(hikers) == 2:
        d0, m0 = hikers[0]
        d1, m1 = hikers[1]
        if m0 == m1:
            return 0
        if m0 < m1:
            d0, d1 = d1, d0
            m0, m1 = m1, m0
        return 1 if d0*m0 + (360-d1)*m1 <= (m0-m1)*360 else 0

    return -1


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
