
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
    d = {}
    N = int(get_line())
    for i in range(2*N-1):
        s = get_line().split()
        for v in s:
            # print v
            if v in d:
                d[v] += 1
            else:
                d[v] = 1
    ans = []
    for v in d:
        if d[v] % 2:
            ans.append(v)
    ans = sorted([int(s) for s in ans])
    ans = [str(i) for i in ans]
    # print ans
    return ' '.join(ans)


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
