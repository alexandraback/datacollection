
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
    smax = int(s[0])
    persons = [int(i) for i in s[1]]
    ans = 0
    cur = 0
    for i in range(len(persons)):
        if cur < i:
            ans += i - cur
            cur += i - cur
        cur += persons[i]
    return ans


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
