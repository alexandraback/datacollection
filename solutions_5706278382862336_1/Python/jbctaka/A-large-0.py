#!python
#-*- coding:utf-8 -*-

import sys
from fractions import Fraction

T = int( sys.stdin.readline() )
for index in range(T):
    val = Fraction( sys.stdin.readline() )
    n = val.numerator
    d = val.denominator
    if d & ( d - 1 ) != 0:
        print "Case #%d: impossible" % ( index + 1 )
        continue
    for i in range(1, 41):
        if val >= Fraction( 1, 2 ** i ):
            print "Case #%d: %d" % ( index + 1, i )
            break
   