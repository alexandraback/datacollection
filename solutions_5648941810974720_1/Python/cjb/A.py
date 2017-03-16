import os
import sys
from subprocess import call
import subprocess
import re
import numpy as np
import pandas as pd
import scipy as sp
import itertools
from collections import defaultdict

home = os.path.expanduser("~")

# zero, small0, large
def openFile(ftype='small-attempt0', prob='A'):
    fname = '{}/Desktop/{}-{}.in'.format(home,prob,ftype)
    f = open(fname)
    lines = [x.rstrip() for x in f.readlines()]
    n = int(lines[0])
    if len(lines) > 1:
        lines = lines[1:]
    print n
    return n, lines

def go(n, lines, prob='A'):
    foutname = '{}/Desktop/{}.out'.format(home, prob)
    print foutname
    f2 = open(foutname,'w')
    for i in range(0, n):
        m = lines[i]
        s = solve(m)
        fmt = 'Case #{}: {}\n'.format(i+1, s)
        f2.write(fmt)
        print m, ': ', fmt.rstrip()
    f2.close()

def makedict(s):
    d = defaultdict(int)
    for i in s:
        d[i] += 1
    return d
def subdict(d, d2,n):
    for k in d2.keys():
        d[k] -= d2[k]*n
    return d

l = []
words = ['ZERO','ONE','TWO','THREE','FOUR','FIVE','SIX','SEVEN','EIGHT','NINE']
for i in range(0, 10):
    l.append(makedict(words[i]))

def solve(m):
    d = makedict(m)
    dd = defaultdict(int)
    dd[2] = d['W']
    dd[4] = d['U']
    dd[6] = d['X']
    dd[8] = d['G']
    dd[0] = d['Z']
    for k in [0,2,4,6,8]:
        subdict(d,l[k],dd[k])
    dd[5] = d['F']
    dd[3] = d['H']
    dd[1] = d['O']
    dd[7] = d['S']
    for k in [3,5,1,7]:
        subdict(d,l[k],dd[k])
    dd[9] = d['I']
#    d = {x : d[x] for x in d.keys() if d[x] != 0}
    ret = ''
    for i in sorted(dd.keys()):
        for j in range(0, dd[i]):
            ret += '{:d}'.format(i)
    return ret
try:
    #n, lines = openFile(ftype='zero')
    n, lines = openFile(ftype='small-attempt0')
    #n, lines = openFile(ftype='large')
    go(n, lines)
except:
    print 'failed'
    pass
