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

def make_a_dictionary():
    d = {}
    def translate(a, b):
        for k,v in zip(a,b):
            if k in d: 
                assert d[k] == v, '{0} gives "{1}" or "{2}"'.format(k, d[k], v)
            if k != ' ':
                d[k] = v

    translate('yeq', 'aoz')
    translate(
        'ejp mysljylc kd kxveddknmc re jsicpdrysi',
        'our language is impossible to understand')

    translate(
        'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
        'there are twenty six factorial possibilities')

    translate(
        'de kr kd eoya kw aej tysr re ujdr lkgc jv',
        'so it is okay if you want to just give up')

    translate('qz', 'zq')

    for c in 'abcdefghijklmnopqrstuvwxyz':
        if c not in d: print c
        if c not in d.values(): print c


    assert len(d) == 26
    return d

goo = make_a_dictionary()

def solve(fin):
    sent = fin.next().strip()
    out = ''.join(map(lambda k: goo.get(k, ' '), sent))

    return out


#####################################################

if __name__=='__main__': dorun()
