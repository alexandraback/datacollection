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
    lst = map(int, fin.next().split())
    N, S, p = lst[:3]
    t = lst[3:]

    def score(tx):
        if tx == 0: return (0, 0)
        if tx == 1: return (1, 1)
        return ((tx - 1) // 3 + 1, (tx + 1) // 3 + 1)

    result = 0
    for no, su in reversed(sorted(map(score, t))):
        if no >=p: result += 1
        elif su >=p and S: result += 1; S -= 1
    
    return result

#####################################################

if __name__=='__main__': dorun()
