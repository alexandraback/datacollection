
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


def calc_one(nums, r):
    ans = r
    for i in nums:
        ans += (i - 1) / r
    return ans
    

def calc():
    D = int(get_line())
    nums = [int(i) for i in get_line().split(' ')]

    maxn = max(nums)
    ans = maxn
    for i in range(1, maxn + 1):
        t = calc_one(nums, i)
        if t < ans:
            ans = t
    return ans


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
