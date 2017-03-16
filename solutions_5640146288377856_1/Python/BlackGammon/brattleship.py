from sys import *
import numpy as np


def readval(fi, ty): return ty(fi.readline())


def readtab(fi, ty): return tuple(map(ty, fi.readline().split()))


fi = open(argv[1], 'r')
T = readval(fi, int)
for k in range(T):
    R, C, W = readtab(fi, int)
    print "Case #" + str(k + 1) + ": " + str((C / W) * R + W - (C % W == 0))