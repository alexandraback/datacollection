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
    L = map(int, fin.next().split())
    del L[0]

    S = sum(L)
    C = len(L)

    Best = set()
    while 1:
        pp = []
        for J in L:
            if J not in Best:                
                M = (S + sum( i for i in L if i not in Best )) / C
    
                if M - J <= 0: # гарантировано проходит
                    Best.add(J)
                    C -= sum(1 for i in L if i == J)
                    pp = 0
                    break
                
                p = (M - J) / S            
            else:
                p = 0

            pp += [ p * 100 ]
        if pp: break
                
    return ' '.join( ('%.06f' % p) for p in pp )
      
#####################################################

if __name__=='__main__': dorun()
