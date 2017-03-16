
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


def ok(a, V):
    l = list(a)
    v = [0]*(V+1)
    for i in range(1<<len(l)):
        n = 0
        for j in range(len(l)):
            if (i & (1<<j)) != 0:
                n += l[j]
        if n <= V:
            v[n] = 1
    for i in range(1, V + 1):
        if v[i] != 1:
            return False
    return True

def calc():
    s = get_line().split()
    C, D, V = int(s[0]), int(s[1]), int(s[2])
    s = get_line().split()
    existing = set([int(i) for i in s])

    # print list(existing), V

    pre = 0
    if 1 not in existing:
        existing.add(1)
        pre = 1
    if 2 not in existing and V >= 2:
        existing.add(2)
        pre += 1

    ans = 3
    cands = [4, 8, 16]
    for i in range(8):
        a = existing.copy()
        for j in range(3):
            if (i & (1<<j)) != 0:
                a.add(cands[j])
        if ok(a, V):
            d = len(a - existing)
            if d < ans:
                ans = d

    if ans <= 1:
        return ans + pre

    for i in range(1, 31):
        a = existing.copy()
        a.add(i)
        if ok(a, V):
            return pre + 1

    for i in range(1, 31):
        for j in range(i + 1, 31):
            a = existing.copy()
            a.add(i)
            a.add(j)
            if ok(a, V):
                return pre + 2

    return ans + pre


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
