#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    line = fin.readline().strip() + '+'
    last = line[0]
    count = 0
    for c in line:
        if c != last:
            count += 1
        last = c

    print("Case #%d: %s" % (case, count))

