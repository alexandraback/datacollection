#!/usr/bin/env python

import sys

def max_result_s(points):
    mmm = 0
    for i in xrange(11):
        for j in xrange(max(i-2, 0), min(11, i+3)):
            k = points - i - j
            if k < 0 or k > 10: continue
            if i - k > 2 or k - i > 2 or j - k > 2 or k - j > 2: continue
            mmm = max([mmm, i, j, k])
    return mmm

def max_result(points):
    mmm = 0
    for i in xrange(11):
        for j in xrange(max(i-1, 0), min(11, i+2)):
            k = points - i - j
            if k < 0 or k > 10: continue
            if i - k > 1 or k - i > 1 or j - k > 1 or k - j > 1: continue
            mmm = max([mmm, i, j, k])
    return mmm


for i, line in enumerate(sys.stdin.readlines()[1:]):
    line = [int(x) for x in line.split()]
    googlers, surprising, p = line[:3]
    t = line[3:]
    values = [[max_result(x), max_result_s(x)] for x in t]
    count = 0
    for v, v_s in values:
        if v >= p:
            count += 1
        elif v_s >= p and surprising > 0:
            count += 1
            surprising -= 1
    
    print "Case #%d: %d" % (i+1, count)
    
        

