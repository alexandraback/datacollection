#!/usr/bin/env python2
# -*- coding: utf-8 -*-

from sys import stdin

C = int(stdin.readline())
for c in range(1,C+1):
    l = []
    x, y = map(int , stdin.readline().split())
    for i in range(0, x):
        l.append(map(int , stdin.readline().split()))

    maxy =  map(max, l)
    maxx =  map(max, [list(i) for i in zip(*l)])

    possible = True
    for x, r in enumerate(l):
        for y, height in enumerate(r):
            #print height, x, y
            if maxx[y] > height and maxy[x] > height:
                possible = False
                break
        if possible == False:
            break
    if possible:
        print "Case #%d: YES" % c
    else:
        print "Case #%d: NO" % c
