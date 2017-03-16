#!/usr/bin/python

#
# Google codejam solution
# David Volgyes
# 
#

import sys, math, os
#import mpmath as mp    # see https://code.google.com/p/mpmath/
import numpy as np     # see http://www.numpy.org/
import sympy as sp     # see https://code.google.com/p/sympy/
import networkx as nx  # see http://networkx.github.com/
import re
import random
import math
from math import floor
import itertools

cases = int(sys.stdin.readline())

def solve(E,Emax,R,N,vi):
    if len(vi)==0: return 0

    m=solve(min(Emax,E+R),Emax,R,N-1,vi[1:])
    for e in range(1,E+1):
        m=max(m,vi[0]*e+solve(min(Emax,E-e+R),Emax,R,N-1,vi[1:]))
    return m

for case in range(1,cases+1):
    E,R,N = map(int,(sys.stdin.readline().strip().split()))
    vi=map(int,(sys.stdin.readline().strip().split()))
    solution=solve(E,E,R,N,vi)
    print "Case #%i: %s" % (case,solution)
