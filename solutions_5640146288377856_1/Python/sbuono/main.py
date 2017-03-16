#! /usr/bin/python

__author__ = 'sbuono'

import sys

with open(sys.argv[1], 'r') as f:
    nbtests = int(f.readline())
    lines = f.readlines()

for testnb, line in zip(range(1, nbtests+1), lines):

    R, C, W = (int(x) for x in line.strip().split())

    if C % W == 0:
        res = R * ((C / W) - 1) + R - 1 + W
    else:
        res = R * (C / W) + W



    print "Case #%d: %d" % (testnb, res)