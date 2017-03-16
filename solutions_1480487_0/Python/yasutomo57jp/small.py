#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import math
import itertools
from multiprocessing import Pool
import numpy

def tof(f):
    return "%.6f" % (f)

def f(line_str):
    tmp = line_str[0].split(" ")
    n=int(tmp[0])
    j=numpy.array(map(int,tmp[1:]),dtype=numpy.float)

    x=numpy.sum(j)
    #k=numpy.clip(2*x/n - j , 0, x)
    k=2*x/n - j
    idx = k>=0
    if numpy.all( idx):
        l=k/x*100
    else:
        p=len(j[idx])
        x2=numpy.sum(j[idx])
        k2=numpy.clip((x+x2)/p -j, 0, x)
        l=k2/x*100

    return " ".join(map( tof, l))

lines=int(sys.stdin.readline().strip())
line_strs=[]
for i in range(lines):
    line_strs.append([sys.stdin.readline().strip()])

p=Pool(24)
#result=p.map(f, line_strs)
result=map(f, line_strs)

for i,r in enumerate(result):
    print "Case #%d: %s" % (i+1, r)

