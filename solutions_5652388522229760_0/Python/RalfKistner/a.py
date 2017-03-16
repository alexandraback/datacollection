#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys
# from Set import Set

def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N = int(fin.readline())
    found = set()
    if N == 0:
        result = 'INSOMNIA'
    else:
        r = 0
        while len(found) < 10:
            r += N
            digits = str(r)
            for d in digits:
                found.add(d)
        result = str(r)



    print("Case #%d: %s" % (case, result))

