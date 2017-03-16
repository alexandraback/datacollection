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
    x,y = map(int, fin.next().split())

    def dostep(step, cx, cy):
        dx, dy = x - cx, y - cy
        if (dx, dy) == (0, 0):
            return ''

        if abs(dx) > abs(dy):
            if abs(dx) > step:
                if dx > 0: return 'E' + dostep(step+1, cx + step, cy)
                else:      return 'W' + dostep(step+1, cx - step, cy)
            else:
                if dx > 0: return 'WE' + dostep(step+2, cx + 1, cy)
                else:      return 'EW' + dostep(step+2, cx - 1, cy)
        else:
            if abs(dy) > step:
                if dy > 0: return 'N' + dostep(step+1, cx, cy + step)
                else:      return 'S' + dostep(step+1, cx, cy - step)
            else:
                if dy > 0: return 'SN' + dostep(step+2, cx, cy + 1)
                else:      return 'NS' + dostep(step+2, cx, cy - 1)

    result = dostep(1, 0, 0)
    # cx, cy, s = 0, 0, 1
    # for c in result:
    #     if c == 'E': cx += s
    #     elif c == 'W': cx -= s
    #     elif c == 'N': cy += s
    #     elif c == 'S': cy -= s
    #     s += 1
    # print
    # print result, cx, cy, x, y
    # assert (cx, cy) == (x, y)

    return result


#####################################################

if __name__=='__main__': dorun()
