
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
    K = int(s[0])
    L = int(s[1])
    S = int(s[2])

    kb = {}
    s = get_line()
    for ch in s:
        kb.setdefault(ch, 0)
        kb[ch] += 1

    target = get_line()
    p = 1
    for ch in target:
        p *= kb.get(ch, 0)

    MM = -1
    for i in range(1, len(target)):
        if target[i:] == target[0:len(target)-i]:
            MM = i
            break
    if MM == -1:
        MM = S / len(target)
    else:
        MM = (S-L)/MM + 1
    
    if p == 0:
        MM = 0

    p = p * (S - L + 1) * 1.0 / (K**len(target))
    return MM - p


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
