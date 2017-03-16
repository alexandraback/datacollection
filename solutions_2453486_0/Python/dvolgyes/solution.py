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

fieldX=np.zeros( (4,4), dtype=np.uint8 )
fieldO=np.zeros( (4,4), dtype=np.uint8 )

def solve(x):
    solution=False
    for i in range(0,4):
        subsolution1=True
        subsolution2=True        
        for j in range(0,4):
            if x[i,j]==0: subsolution1=False
            if x[j,i]==0: subsolution2=False            
        if subsolution1 or subsolution2: return True
    if x[0,0]+x[1,1]+x[2,2]+x[3,3]==4: return True
    if x[0,3]+x[1,2]+x[2,1]+x[3,0]==4: return True    
    return False

for i in range(0,T):
    fieldX.fill(0)
    fieldO.fill(0)
    counter=0
    empty=False
    while counter<4:
        sline=sys.stdin.readline().strip()
        if len(sline)<4:continue

        for j in range(0,4):
            if sline[j]=='X' or sline[j]=='T':
                fieldX[counter,j]=1
            if sline[j]=='O' or sline[j]=='T':
                fieldO[counter,j]=1
                continue
            if sline[j]=='.':
                empty=True
        counter+=1
        
    if solve(fieldX): 
        print "Case #%i: X won" % (i+1,)
        continue
    if solve(fieldO): 
        print "Case #%i: O won" % (i+1,)
        continue
    if empty:
        print "Case #%i: Game has not completed" % (i+1,)
        continue
    print "Case #%i: Draw" % (i+1,)
