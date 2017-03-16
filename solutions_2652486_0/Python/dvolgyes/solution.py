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

def prime_factors(N):
    result=[]
    if N==1: return result
    i=2
    while i<N:
        if N%i>0:
            i+=1
            continue
        return [i]+prime_factors(N/i)
    return []

def merge(m1,p1):
    m2=dict()
    for i in range(0,12):
        m2[i]=0
    for p in p1:
        m2[p]+=1
    m=dict()
    for i in range(0,12):
        v=max(m1[i],m2[i])
        m[i]=v
    return m
    
def digits(N,M,Kset):
    for i in range(2,M+1):
        for j in range(2,M+1):
            for k in range(2,M+1):
                OK=True
                for test in Kset:
                    OK = OK and (i*j*k==test or i*j==test or j*k==test or i*k==test or test==1 or test==i or test==j or test==k)
                if OK: return ["%i%i%i" % (i,j,k)]
    return ["2"*N]
    
    return ["TEST"]

def solve(R,N,M,K,Kset):
    result=[]
    for r in range(0,R):
        result+=digits(N,M,Kset[r])
    return result

for case in range(1,cases+1):
    R,N,M,K = map(int,(sys.stdin.readline().strip().split()))
    Kset=[]
    for i in range(0,R):
        Kset.append(map(int,(sys.stdin.readline().strip().split())))
    solution=solve(R,N,M,K,Kset)
    print "Case #%i:" % (case)
    for line in solution:
        print line
