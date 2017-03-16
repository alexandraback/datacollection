#! /opt/local/bin/python
from numpy import *
from itertools import *
import sys
sys.setrecursionlimit(10000)
#from gmpy2 import *
#f=open('test2')
f=open('B-small-attempt0.in')
#f=open('A-large.in')
T=int(f.readline())
def chkprefix(prefix):
    seen = set([])
    current=''
    for c in prefix:
        if c in seen and not c==current:
            return False
        if not c==current:
            current = c
        if c not in seen:
            seen.add(c)
    return True
def solve(prefix,strs,chrpre,chrstrs):
    #print 'prefix',prefix,'set',strs
    if not chkprefix(prefix):
        #print 'prefix',prefix,' returned 0'
        return 0
    if len(strs)==0:
        return 1
    val = 0
    for ii in range(len(strs)):
        #print chrpre&chrstrs
        if  ( len(chrpre&chrstrs)==0) or  (prefix == '' or prefix[-1]==strs[ii][0]):
                tmp = strs[:]
                tmp.pop(ii)
                tmpchrstrs=set([])
                tmpchrpre = chrpre.copy()
                for c in strs[ii]:
                    tmpchrpre.add(c)
                for st in tmp:
                    for ch in st:
                        tmpchrstrs.add(ch)
                val += solve(prefix+strs[ii],tmp,tmpchrpre,tmpchrstrs)
    return val

for tt in range(1,T+1):
    N=int(f.readline())
    strs = f.readline().split()
    strchrs= {}
    for st in strs:
        strchrs = {}
        for c in st:
            strchrs.add(c)
    print 'Case','#'+str(tt)+':',solve('',strs,set([]),strchrs)

