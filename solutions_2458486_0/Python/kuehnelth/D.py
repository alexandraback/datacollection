#!/usr/bin/env python2
# -*- coding: utf-8 -*-

from sys import stdin

def solve(keys, chests, way=""):
    if len(chests) == 0: return way
    if len(keys) == 0: return "IMPOSSIBLE"
    for chest in chests:
        if chest[1] in keys:
            keysnew = keys[:]
            keysnew.remove(chest[1])
            for k in chest[3:]:
                keysnew.append(k)
            chestsnew = chests[:]
            chestsnew.remove(chest)
            res = solve(keysnew, chestsnew, way + str(chest[0]) + ", ")
            if res != "IMPOSSIBLE":
                return res
    return "IMPOSSIBLE, "
    
C = int(stdin.readline())
for c in range(1,C+1):
    k, n = map(int, stdin.readline().split())
    keys = map(int, stdin.readline().split())

    chests = []
    for i in range(0, n):
        chests.append([i + 1] + map(int, stdin.readline().split()))

    print "Case #%d: %s" % (c, solve(keys, chests)[:-2])
