#! /usr/bin/env python
from __future__ import print_function, division
try:
    range = xrange
except NameError:
    pass

# import collections
# import functools
# import itertools as it
# import numpy as np # See http://www.numpy.org
# import sympy as sp # See http://sympy.org/en/index.html
# import gmpy2 # See https://code.google.com/p/gmpy/
# import networkx as nx # See http://networkx.github.io/

import os
import sys
# MY MODULES - available at https://github.com/lackofcheese/CodeJamLib/
sys.path.append(os.path.join(
    os.environ['GOOGLE_DRIVE'], 'Coding', 'GCJ', 'CodeJamLib'))
import codejam_io
import collections

def toks_line(f_in, fun=int):
    return [fun(k) for k in f_in.readline().split()]

def process_first(f_in):
    num_cases = int(f_in.readline())
    other_data = None
    return num_cases, other_data

def process_case(f_in, f_out, case_no, other_data=None):
    D = int(f_in.readline())
    pancake_counts = toks_line(f_in)
    diner_counts = collections.Counter()
    for np in pancake_counts:
        diner_counts[np] += 1
    diner_counts = sorted(diner_counts.items(), reverse=True)
    ans = solve(diner_counts)
    print("Case #{}: {}".format(case_no, ans), file=f_out)

def solve(dc):
    min_steps = dc[0][0]
    for max_stack in range(2, dc[0][0]):
        num_steps = max_stack
        for np, count in dc:
            if np <= max_stack:
                break
            num_steps += ((np - 1) // max_stack) * count
        if num_steps < min_steps:
            min_steps = num_steps
    return min_steps

if __name__ == '__main__':
    codejam_io.process_input(process_case, process_first, __file__)
