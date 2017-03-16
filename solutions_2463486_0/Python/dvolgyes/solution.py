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
import math

T=int(sys.stdin.readline())

def square(x):
    sx=int(math.sqrt(x))
    return sx*sx==x
    
def palindrome(x):
    xstr=str(x)
    for i in range(0,len(xstr)):
        if xstr[i]!=xstr[len(xstr)-1-i]: return False
    return True

def solve(A,B):
    counter=0
    for i in range(A,B+1):
        if square(i) and palindrome(i) and palindrome(int(math.sqrt(i))): 
            counter+=1
    return counter

for i in range(0,T):
    sline=sys.stdin.readline().strip()
    N,M=map(int,sline.split())
    print "Case #%i: %i" % (i+1,solve(N,M))

