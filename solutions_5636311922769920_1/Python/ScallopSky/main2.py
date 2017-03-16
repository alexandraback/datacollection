#! /usr/bin/env python

import math

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d: " % Case,
    t = map(int, raw_input().split())
    k = t[0]
    c = t[1]
    s = t[2]

    if s*c < k:
        print "IMPOSSIBLE"
        continue

    level = 0
    cur = 0
    ans = []
    for i in range(k):
        cur = cur * k + i
        level += 1
        # print "STEP", i, level, cur
        if level == c:
            ans += [cur+1]
            level = 0
            cur = 0
    if level:
        ans += [cur+1]
    print " ".join([ str(x) for x in ans ])
