#!/usr/bin/env python

import sys
import math

line = raw_input()
count = int(line)
for case in xrange(1, count+1):
    line = raw_input()
    (r,t) = [ int(x) for x in line.split()]
    a = 2
    b = 2 * r + 3
    c = 2 * r + 1 - t
    delta = b * b - 4 * a * c
    root = ( -1 * b +  math.sqrt(delta) ) / ( 2 * a)
    out = int(root)
    while ( a * out * out + b * out + c > 0):
        out -= 1
    while ( a * out * out + b * out + c <= 0 ):
        out += 1
    print "Case #%d: %d" % (case,out)




