from collections import defaultdict, Counter
import collections
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
def openFile(ftype, prob='B'):
    fname = '{}/Desktop/{}-{}.in'.format(home,prob,ftype)
    f = open(fname)
    lines = [x.rstrip() for x in f.readlines()]
    n = int(lines[0])
    if len(lines) > 1:
        lines = lines[1:]
    print n
    return n, lines

def go(n, lines, prob='B'):
    foutname = '{}/Desktop/{}.out'.format(home, prob)
    print foutname
    f2 = open(foutname,'w')
    offset = 0
    for i in range(0, n):
        m = int(lines[offset])
        soldiers = lines[offset+1:offset+2*m]
        offset += 2*m        
        s = solve(m, soldiers)
        fmt = 'Case #{}: {}\n'.format(i+1, s)
        f2.write(fmt)
        print m, ':', offset, ': ', fmt.rstrip()
    f2.close()

def solve(m, lines):
    ct = Counter()
    for line in lines:
        guys = [int(x) for x in line.split(' ')]
        ct.update(guys)
    mx = max([x for x in ct.values()])
    soln = []
    for elt in ct:
        if ct[elt] % 2 == 1:
            #print 'elt is ', elt
            soln += [elt]
    soln = sorted(soln)
    print ct, mx, soln
    return ' '.join([str(x) for x in soln]) 
#n, lines = openFile(ftype='zero')
#n, lines = openFile(ftype='small-attempt0')
n, lines = openFile(ftype='large')
go(n, lines)
