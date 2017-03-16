#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N = int(fin.readline())
    hikers = []
    for i in range(N):
        d, h, m = map(int, fin.readline().split())
        for p in range(m, m+h):
            rev = p * (360-d) / 360.0
            hikers.append({'start': d, 'p': p, 't': rev})
    hikers.sort(key=lambda hiker: -hiker['t'])
    debug(hikers)
    M = len(hikers)
    best = []
    for i in range(M+1):
        count = 0
        if i < M:
            finish_at = hikers[i]['t']+0.000000000001
        else:
            finish_at = 0
        for h in hikers:
            first_rev = h['t']
            if finish_at < first_rev:
                # deer pass hiker
                count += 1
            else:
                rem = finish_at - first_rev
                times = int(rem / h['p'])
                count += times
        best.append(count)
    result = min(best)
    print("Case #%d: %s" % (case, result))
