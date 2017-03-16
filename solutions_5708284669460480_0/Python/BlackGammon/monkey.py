from sys import *
import numpy as np


def readval(fi, ty): return ty(fi.readline())


def readtab(fi, ty): return tuple(map(ty, fi.readline().split()))


def size(t, L):
    for d in range(1, L):
        possible = True
        for i in range(L - d):
            if possible:
                possible = t[i] == t[d + i]
        if possible:
            return d
    return L


fi = open(argv[1], 'r')
T = readval(fi, int)
for k in range(T):
    K, L, S = readtab(fi, int)
    keys = list(fi.readline())
    dict = {}
    for key in keys:
        if key in dict:
            dict[key] += 1.0
        else:
            dict[key] = 1.0
    target = list(fi.readline())
    R = size(target, L)
    p = 1.0
    possible = True
    for c in target[:-1]:
        if possible:
            if c in dict:
                p *= dict[c] / K
            else:
                possible = False
    a = 0.0
    if possible:
        maxi = (S - L) / R + 1
        expected = p * (S - L + 1)
        a = maxi - expected
        # print p, maxi, expected
    print "Case #" + str(k + 1) + ": " + str(a)