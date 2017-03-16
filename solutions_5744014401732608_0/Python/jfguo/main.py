
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

def ok(rec, B, M):
    f = [0 for i in range(B)]
    f[0] = 1
    for i in range(B):
        for j in range(0, i):
            if rec[j][i]:
                f[i] += f[j]
    return f[B - 1] == M

def recusive(rec, B, M, r, c):
    if ok(rec, B, M):
        return True

    rec[r][c] = 1
    if ok(rec, B, M):
        return True

    nr = r
    nc = c + 1

    if nc == B:
        nr += 1
        nc = nr + 1

    if nr < B - 1:
        if recusive(rec, B, M, nr, nc):
            return True
    rec[r][c] = 0

    if nr < B - 1:
        if recusive(rec, B, M, nr, nc):
            return True
    return False


def calc(case):
    s = get_line().split()
    B = int(s[0])
    M = int(s[1])

    rec = [[0 for i in range(B)] for j in range(B)]

    res = recusive(rec, B, M, 0, 1)
    if not res:
        print('Case #%d: IMPOSSIBLE' % case)
        return
        
    print('Case #%d: POSSIBLE' % case)
    for line in rec:
        print ''.join([str(i) for i in line])


T = int(get_line())
for i in range(1, T + 1):
    calc(i)
