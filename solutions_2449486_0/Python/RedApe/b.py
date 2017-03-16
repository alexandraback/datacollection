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

def solve(fin):
    N,M = map(int, fin.next().split())
    lawn = [map(int, fin.next().split()) for _ in xrange(N)]
    lawn = dict( ((x,y), lawn[y][x]) for y in xrange(N) for x in xrange(M))
    for y in xrange(N):
        for x in xrange(M):
            it = lawn[x,y]
            U = [lawn[x,a] for a in xrange(y)]
            D = [lawn[x,a] for a in xrange(y+1,N)]
            L = [lawn[a,y] for a in xrange(x)]
            R = [lawn[a,y] for a in xrange(x+1,M)]
            possV = max(U+[0]) <= it >= max(D+[0])
            possH = max(L+[0]) <= it >= max(R+[0])
            if not possV and not possH:
                return 'NO'
    return 'YES'

#####################################################

if __name__=='__main__': dorun()
