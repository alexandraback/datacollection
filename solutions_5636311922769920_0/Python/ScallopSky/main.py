#! /usr/bin/env python

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d: " % Case,
    t = map(int, raw_input().split())
    k = t[0]
    c = t[1]
    s = t[2]

    if s<k:
        print "IMPOSSIBLE"
        continue

    for i in range(k):
        x = i
        for j in range(c-1):
            x = x * k + i
        print x+1,
    print
