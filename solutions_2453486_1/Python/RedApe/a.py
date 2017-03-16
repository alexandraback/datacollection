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
    field = {}
    for r in xrange(4):

        line = None
        while not line:
            line = fin.next().strip()

        for c in xrange(4):
            field[c,r] = line[c]

    def check(lst):
        lst = set(lst) - {'T'}
        if len(lst)==1:
            item = lst.pop()
            return item if item!='.' else None
        return None


    while 1:
        result = check(field[a,a] for a in xrange(4))
        if result: break

        result = check(field[a,3-a] for a in xrange(4))
        if result: break
        for v in xrange(4):
            result = check(field[v,a] for a in xrange(4))
            if result: break

            result = check(field[a,v] for a in xrange(4))
            if result: break
        break

    if result:
        return '%s won' % result
    elif '.' in set(field.values()):
        return 'Game has not completed'
    else:
        return 'Draw'


#####################################################

if __name__=='__main__': dorun()
