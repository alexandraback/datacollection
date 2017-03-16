#! /usr/bin/python

__author__ = 'BJG Association'

### IMPORTS ###
import sys
import math
import numpy as np
import scipy.ndimage as ndi
from pprint import pprint

def pos(k, steps):
    p = 0

    for i, step in zip(range(len(steps),0,-1), steps):
        p += k**(i-1) * step

    return p + 1

def solve(k, c, s):
    if s < float(k)/c:
        return "IMPOSSIBLE"

    index = 0
    required_students = int(math.ceil(float(k) / c))
    tiles = []

    for _ in range(required_students):
        steps = [s % k for s in xrange(index, index + c)]
        tiles.append(pos(k, steps))

        index += c

    return ' '.join([str(t) for t in tiles])

### PROCESS INPUT FILE ###

if __name__ == '__main__':
    f = open(sys.argv[1])
    fout = open(sys.argv[1].replace('.in','.out'),'w')

    T = int(f.readline())

    for case in xrange(T):
        k, c, s = [int(x) for x in f.readline().strip().split()]

        ans = solve(k, c, s)
        print "case %s: (%d, %d, %d) ans: %s" % (case, k, c, s, ans)
        fout.write('Case #%d: %s\n'%(case+1, ans))
