
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


def calc(case):
    s = get_line().split()
    B = int(s[0])
    M = int(s[1])

    if M > (1<<(B-2)):
        print('Case #%d: IMPOSSIBLE' % case)
        return

    rec = [[0 for i in range(B)] for j in range(B)]

    f = [0 for i in range(B)]
    f[0] = 1
    f[1] = 1
    for i in range(2, B - 1):
        f[i] = 2 * f[i-1]

    for i in range(B):
        for j in range(B):
            if j != B-1 and j > i:
                rec[i][j] = 1

    #print f
    i = B - 2
    while M:
        #print M, i
        if M >= f[i]:
            rec[i][B-1] = 1
            M -= f[i]
        i -= 1


    print('Case #%d: POSSIBLE' % case)
    for line in rec:
        print ''.join([str(i) for i in line])


T = int(get_line())
for i in range(1, T + 1):
    calc(i)
