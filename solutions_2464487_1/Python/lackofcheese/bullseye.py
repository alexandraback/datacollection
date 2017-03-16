from __future__ import print_function, division
try:
    range = xrange
except NameError:
    pass
import os
import sys

import collections
import functools
import itertools as it
import numpy as np # See http://www.numpy.org/
import gmpy2 as g2 # See https://code.google.com/p/gmpy/
#import networkx as nx # See http://networkx.github.io/

# MY MODULES
sys.path.append(os.path.join(os.environ['GOOGLE_DRIVE'], 'Coding', 'GCJ'))
import proc

def toks_line(f, fun=lambda x: x):
    return [fun(k) for k in f.readline().strip().split()]

def process_first(f):
    num_cases = int(f.readline())
    other_data = None
    return num_cases, other_data

def process_case(f, f_out, case_no, other_data):
    r, t = toks_line(f, int)
    ans = solve(r, t)
    print("Case #{}: {}".format(case_no, ans), file=f_out)

def solve(r, t):
    b = 2*r-1
    n = (g2.isqrt(b**2+8*t) - b) // 4
    return n

if __name__ == '__main__':
    proc.process_input(process_case, process_first)
