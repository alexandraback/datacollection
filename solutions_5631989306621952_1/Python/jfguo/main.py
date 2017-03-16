
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
    line = get_line()
    ans = line[0]
    for i in range(1, len(line)):
        if line[i] >= ans[0]:
            ans = line[i] + ans
        else:
            ans = ans + line[i]
    return ans


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
