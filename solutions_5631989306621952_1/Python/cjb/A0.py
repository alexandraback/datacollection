import os
import sys
from subprocess import call
import subprocess
import re
import numpy as np
import pandas as pd
import scipy as sp
import itertools

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

def solve(m):
    if len(m) == 1:
        return m
    l1 = set(m[0])
    l2 = set()
    for c in m[1:]:
        for x in l1:
            l2 = l2 | {x+c, c+x}
        l1 = set(sorted(l2)[-1:])
        l2 = set()
    return sorted(l1)[-1]

#n, lines = openFile(ftype='zero')
#n, lines = openFile(ftype='small-attempt0')
n, lines = openFile(ftype='small-attempt1')
go(n, lines)
