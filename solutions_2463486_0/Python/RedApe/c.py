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

isPoly = lambda x: ''.join(reversed(str(x))) == str(x)

def solve(fin):
    A,B = map(int, fin.next().split())

    rA = int(sqrt(A))
    rB = int(sqrt(B))+1

    counter = 0
    for a in takewhile(lambda x: x<rB, count(rA)):
        if not isPoly(a):
            continue

        if isPoly(a*a):
            if not A <= a*a <= B:
                continue

            counter += 1

    return counter

#####################################################

if __name__=='__main__': dorun()
