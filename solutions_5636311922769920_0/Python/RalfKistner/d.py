#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    K, C, S = map(int, fin.readline().split())
    if K > C*S:
        result = 'IMPOSSIBLE'
    else:
        p = 0
        numbers = []
        while p < K:
            nr = 0
            for c in range(C):
                if p < K:
                    nr += p * (K**c)
                    p += 1
            numbers.append(nr + 1)
        result = ' '.join(map(str, numbers))

    print("Case #%d: %s" % (case, result))
