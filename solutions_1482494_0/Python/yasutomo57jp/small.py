#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import math
import itertools
from multiprocessing import Pool
import numpy


def f(line_str):
    n=len(line_str)
    costs=[]
    for i in line_str:
        costs.append(map(int,i.split()))
    costs.sort(cmp=lambda x,y: cmp(x[1]*1000+x[0],y[1]*1000+y[0]))
    costs=numpy.array(costs,dtype=numpy.int)
    result=0
    stars=0

    i=0
    step=0
    while i<len(costs):
    #    print costs,stars
        if costs[i,1]<=stars:
            stars+=2
            costs[i,1]=1001
            if costs[i,0]==1001:stars+=1
            i+=1
            step+=1
        else:
            idx=costs[:,0]<=stars
            found=False
            for j, ix in enumerate(idx):
                if ix==True and costs[j,1]==1001:
                    costs[j,0]=1001
                    stars+=2
                    step+=1
                    found=True
                    break
            if found==False:
                for j, ix in enumerate(idx):
                    if ix==True:
                        costs[j,0]=1001
                        stars+=1
                        step+=1
                        found=True
                        break
            if found==False:
                return "Too Bad"
    
    #print step
    #quit()
    return "%d" % (step)

lines=int(sys.stdin.readline().strip())
line_strs=[]
for i in range(lines):
    n=int(sys.stdin.readline().strip())
    l=[]
    for j in range(n):
        l.append(sys.stdin.readline().strip())
    line_strs.append(l)

p=Pool(24)
result=p.map(f, line_strs)
#result=map(f, line_strs)

for i,r in enumerate(result):
    print "Case #%d: %s" % (i+1, r)

