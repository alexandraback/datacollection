#!/usr/bin/python

import sys

with open(sys.argv[1]) as f:
    lines = f.readlines();

lines.pop(0)

n_case = 0
while lines:
    n_case += 1

    line = lines.pop(0)
    N = int(line)
    level1 = list()
    level2 = list()
    for line in lines[:N]:
        a,b = [int(c) for c in line.split(' ')]
        level1.append(a)
        level2.append(b)
    lines = lines[N:]

    stars = 0
    ret = 0

    while level2:
        ret += 1
        pos = 0
        for x in level2:
            if stars >= x:
                break;
            pos += 1

        if pos < len(level2):
            if level1[pos] == 9999999:
                stars += 1
            else:
                stars += 2
            level2.pop(pos)
            level1.pop(pos)
            continue;

        pos = 0
        for x in level1:
            if stars >= x:
                break;
            pos += 1

        if pos < len(level1):
            level1[pos] = 9999999
            stars += 1
            continue;

        ret = -1
        break;

    if ret != -1:
        print("Case #"+str(n_case)+": "+str(ret))
    else:
        print("Case #"+str(n_case)+": Too Bad")
