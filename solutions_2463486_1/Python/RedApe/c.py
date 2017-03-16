#coding: 1251
#####################################################

from __future__ import division

import os
import sys
import operator
import string
import re
import time

from os.path import splitext
from copy import copy

from math import *
from operator import *
from collections import *
from itertools import *
from functools import *

#####################################################

try:
    from do import report_working_on
except ImportError:
    report_working_on = lambda a,b: None

if len(sys.argv) > 1:
    fin = file(sys.argv[1], 'r')
    fout = file(splitext(sys.argv[1])[0]+'.out', 'w+')
else:
    fin = sys.stdin
    fout = sys.stdout

def dorun():
    cases = int(fin.next())
    for case in xrange(cases):
        report_working_on(case, cases)
        print>>fout, 'Case #%d: %s' % ( 1+case, solve(fin) )
    else:
        report_working_on(0,0)

#####################################################

def isPoly(x):
    s = str(x)
    return ''.join(reversed(s)) == s

# 121 -> 12, 0
# 1231 -> 12, 1
def int2poly(x):
    s = str(x)
    return 1 - len(s) % 2, int(s[: (len(s) + 1) // 2])

# 12,1 -> 1221
# 12,0 -> 121
def poly2int(tx):
    f, n = tx
    s = str(n)
    return int( (s if f == 1 else s[:-1]) + ''.join(reversed(s)) )

def upperBound(tx):
    f,n = tx
    return f, int('9' * len(str(n)))

assert upperBound((0,12)) == (0,99)
assert upperBound((1,12)) == (1,99)

# 0,12 -> 121 -> 999 -> 1001 -> 0,10
# 1,12 -> 1221 -> 9999 -> 10001 -> 0, 100
def overBound(tx):
    f,n = tx
    if f == 0:
        return 1, int('1' + '0' * (len(str(n))-1))
    else:
        return 0, int('1' + '0' * (len(str(n))))

assert overBound((0,12)) == (1,10)
assert overBound((1,12)) == (0,100)

def less(a, b):
    fa, a = a
    fb, b = b
    return \
        a <= b if fa == fb else \
        fa <= fb if len(str(a)) == len(str(b)) else \
        a <= b

def genIt(left, right):
    current = int2poly(left)
    txB = int2poly(right)

    fa, a = txB; a+=1
    txB = fa, a

    # print 'searching from ', left, 'to', right

    while less(current, txB):
        upper = upperBound(current)
        # print 'border:', poly2int(upper)#, 'tx:', poly2int(txB)

        if less(txB, upper):
            upper = txB

        f,x = current
        while x < upper[1]:
            yield poly2int((f,x))
            x += 1

        current = overBound((f,x))
        #print 'next:', poly2int(current), '(%s)' % poly2int(txB)


def solve(fin):
    A,B = map(int, fin.next().split())

    rA = int(sqrt(A))
    rB = int(sqrt(B))+1

    counter = 0
    for a in genIt(rA, rB):
        sq = a*a
        if isPoly(sq):
            if not A <= sq <= B:
                continue

            counter += 1

    return counter

#####################################################

if __name__=='__main__': dorun()
