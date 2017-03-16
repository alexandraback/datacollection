from sys import *
import numpy as np


def readval(fi, ty): return ty(fi.readline())


def readtab(fi, ty): return tuple(map(ty, fi.readline().split()))


fi = open(argv[1], 'r')
T = readval(fi, int)
for k in range(T):
    _, D, V = readtab(fi, int)
    coins = map(int, fi.readline().split())
    s = set()
    s.add(0)
    for c in coins:
        t = set()
        for v in s:
            if v + c <= V:
                t.add(v + c)
        for v in t:
            s.add(v)
    added = 0
    for i in range(1, V + 1):
        if i not in s:
            added += 1
            t = set()
            for v in s:
                if v + i <= V:
                    t.add(v + i)
            for v in t:
                s.add(v)

    print "Case #" + str(k + 1) + ": " + str(added)