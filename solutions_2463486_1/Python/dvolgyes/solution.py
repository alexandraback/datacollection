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
    a=int(math.sqrt(A))
    b=int(math.sqrt(B))
    solution=[]
    counter=0
    if (a*a)<A: a+=1
    for i in range(a,b+1):
        if palindrome(i*i) and palindrome(i):
            counter+=1
            solution.append(i*i)
    return counter,solution

def solve2(A,B,pals):
    counter=0
    for i in pals:
        if i>=A and i<=B: counter+=1
    return counter

cnt,sol=solve(0,1E14)    

for i in range(0,T):
    sline=sys.stdin.readline().strip()
    N,M=map(int,sline.split())
    print "Case #%i: %i" % (i+1,solve2(N,M,sol))

