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
    e, r, n = toks_line(f, int)
    activities = np.array(toks_line(f, int))
    #print()
    #print(e, r)
    ans = solve(e, r, activities)
    print("Case #{}: {}".format(case_no, ans), file=f_out)

def solve(e, r, acts, start=None, end=None):
    if r >= e:
        return e*sum(acts)
    if start is None:
        start = e
    if end is None:
        end = r
    #print(acts, start, end)
    na = len(acts)
    if na == 0:
        return 0

    free = start - end + r*na
    if free < 0:
        print("ERROR! Negative!", file=sys.stderr)
    if free == 0:
        return 0
    value = 0

    i = acts.argmax()
    mid = min(start+r*i, e)
    mid2 = max(r, end-r*(na-i-1))
    #print((i, acts[i]), mid, mid2)
    excess = mid + r - mid2
    value = excess * acts[i]
    #print(excess, value)
    if excess < 0:
        print("Negative!", file=sys.stderr)
    #print()
    value += solve(e, r, acts[:i], start, mid)
    value += solve(e, r, acts[i+1:], mid2, end)
    return value

if __name__ == '__main__':
    proc.process_input(process_case, process_first)
