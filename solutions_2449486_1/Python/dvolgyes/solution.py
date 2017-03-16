#!/usr/bin/python

#
# Google codejam solution
# David Volgyes
# 
#

import sys, math, os
#import mpmath as mp    # see https://code.google.com/p/mpmath/
import numpy as np     # see http://www.numpy.org/
#import sympy as sp     # see https://code.google.com/p/sympy/
import networkx as nx  # see http://networkx.github.com/
import re
import random

T=int(sys.stdin.readline())

def solve(x):
    solution=False
    a=np.repeat(np.amax(x,axis=0).reshape(1,-1),x.shape[0],axis=0)
    b=np.repeat(np.amax(x,axis=1).reshape(-1,1),x.shape[1],axis=1)

    z=np.minimum(a,b)
    return np.all( (x-z)>=0)

for i in range(0,T):
    sline=sys.stdin.readline().strip()
    N,M=map(int,sline.split())
    field=np.zeros( (N,M), dtype=np.int8 )

    for j in range(0,N):
        sline=sys.stdin.readline().strip()
        ints=map(int,sline.split())
        field[j,:]=np.array(ints)
       
    if solve(field): 
        print "Case #%i: YES" % (i+1,)
    else:
        print "Case #%i: NO" % (i+1,)    

