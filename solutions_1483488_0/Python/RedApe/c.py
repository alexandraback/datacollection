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

# 123, 1, 2 => 12

def number(A, B):
    N = len(str(B))

    numbers = set()
    for n in xrange(A, B+1):
        sn = str(n)
        for d in xrange(1, N):
            sm = sn[d:] + sn[:d]
            if sm[0]=='0': continue
            m = int(sm)
            
            if n < m and A <= m <= B: 
                numbers.add((n,m))
    
    return len(numbers)

    
def solve(fin):
    A, B = map(int, fin.next().split())
    return number(A, B)

#####################################################

if __name__=='__main__': dorun()
