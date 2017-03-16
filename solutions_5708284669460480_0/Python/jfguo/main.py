
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



M = 0
total = 0
target = ''
kb = ''
K = 0
L = 0
S = 0


def get_num(s, target):
    ans = 0
    for i in range(len(s)):
        if s[i:i+len(target)] == target:
            ans += 1
    return ans

def gen(s):
    global M
    global total
    # print s, S
    if len(s) == S:
        n = get_num(s, target)
        if n > M:
            M = n
        total += n
        return

    for ch in kb:
        gen(s+ch)


def calc():
    global M
    global total
    global target
    global kb
    global K
    global L
    global S

    s = get_line().split()
    K = int(s[0])
    L = int(s[1])
    S = int(s[2])

    """
    kb = {}
    s = get_line()
    for ch in s:
        kb.setdefault(ch, 0)
        kb[ch] += 1
    """
    kb = get_line()
    M = 0
    total = 0
    target = get_line()
    gen('')

    return M - total*1.0/(K**S)


T = int(get_line())
for i in range(1, T + 1):
    print('Case #%d: %s' % (i, calc()))
