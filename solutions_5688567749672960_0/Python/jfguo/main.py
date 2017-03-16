
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
    ans = [0] * (N + 1)
    for i in range(N + 1):
        ans[i] = i
    for i in range(1, N + 1):
        s = str(i)
        j = int(s[::-1])
        # print i, j
        if j <= N and ans[i] + 1 < ans[j]:
            ans[j] = ans[i] + 1
        if i + 1 <= N and ans[i] + 1 < ans[i + 1]:
            ans[i + 1] = ans[i] + 1
    return ans[N]

T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
