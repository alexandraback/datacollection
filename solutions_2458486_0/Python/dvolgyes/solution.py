#!/usr/bin/python

#
# Google codejam solution
# David Volgyes
# 
#

import sys, math, os
#import mpmath as mp    # see https://code.google.com/p/mpmath/
import numpy as np     # see http://www.numpy.org/
import scipy as sci
#import sympy as sp     # see https://code.google.com/p/sympy/
#import networkx as nx  # see http://networkx.github.com/
import re
import random
import math
from math import floor
from itertools import *

T=int(sys.stdin.readline())

def test(order,locks,keys,av):
    avail=list(av)
    for i in order:
        if locks[i] not in avail: 
            return False
        avail.remove(locks[i])
        avail.extend(keys[i])
    return True

def merge(nz_locked,z_locked,locks,keys,avail,start=0):
    if len(z_locked)==0: return True,nz_locked
    for j in range(0,len(nz_locked)):
	for i in range(0,len(z_locked)):
		if (nz_locked[j]<z_locked[i]): break
		seq1=nz_locked[0:j]+[z_locked[i]]+nz_locked[j:]
		seq2=z_locked[0:i]+z_locked[i+1:]
		if test(seq1,locks,keys,avail)==False: continue
		a,b=merge(seq1,seq2,locks,keys,avail,j)
		if a: return a,b
    return merge(nz_locked+z_locked[0:1],z_locked[1:],locks,keys,avail)
#    return False,[]

def solve(locks,locked,keys,avail,level=1):
    prefix=" "*level*3
    if len(locked)==0: return True,[]
    for l in locked:
        if locks[l] not in avail: continue
        if len(locked)==1: return True,[l]
        nlock=list(locked)
        nlock.remove(l)
        av=list(avail)
        av.remove(locks[l])
        av.extend(keys[l])
        a,b=solve(locks,nlock,keys,av,level+1)
        if a: return True,[l]+b
    return False,[]

for i in range(0,T):
    K,N=map(int,sys.stdin.readline().strip().split())
    avail=list(map(int,sys.stdin.readline().strip().split()))

    locks=[-1]
    nz_locked=[]
    z_locked=[]
    locked=range(1,N+1)
    keys=[[-1]]
    for j in range(0,N):
        tmp=map(int,sys.stdin.readline().strip().split())
        locks.append(tmp[0])
        if tmp[1]>0:
            keys.append(tmp[2:])
            nz_locked.append(j+1)
        else:
            keys.append([])
            z_locked.append(j+1)

    has_solution=False
    has_solution,order=solve(locks,nz_locked,keys,avail)

    if has_solution:
        result=""
        a=False
        a,order=merge(order,z_locked,locks,keys,avail)
        if a==False: order=list(order)+list(z_locked)
        for k in order:
            result+=str(k)+" "
        print "Case #%i: %s" % (i+1,result.strip())
    else:
        print "Case #%i: IMPOSSIBLE" % (i+1)    

