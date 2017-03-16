#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random
import re
import string

inf = float('inf')

def next_line(filename):
    return f.readline().strip('\n')

def solve(R,C,W):
    return int(ceil(1.*C/W) + W - 1)

infile = sys.argv[1]
f = open(infile,'r')

T = int(next_line(f))
for t in range(T):
    R,C,W = map(int,next_line(f).split())
    print 'Case #{}: {}'.format(t+1,solve(R,C,W))
f.close()
