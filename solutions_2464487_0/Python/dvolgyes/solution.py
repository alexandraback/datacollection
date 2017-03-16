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
from mpmath import *
mp.dps = 99

cases = int(sys.stdin.readline())
    
def solve(r,t):
    a=mpf(2)
    b=mpf(2*r-1)
    c=mpf(-t)
    return int( (-b+ sqrt(b*b-4*a*c)) /(2*a))

for case in range(1,cases+1):
    r,t = map(int,(sys.stdin.readline().strip().split()))
    solution=solve(r,t)
#    test(case,r,t)
    print "Case #%i: %s" % (case,solution)
    
