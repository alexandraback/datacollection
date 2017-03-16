#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import math
import itertools
from multiprocessing import Pool
import numpy
import scipy


def f(line_str):
    tmp=line_str.split(" ")
    n=int(tmp[0])
    s=numpy.array(map(int,tmp[1:]))

    sums=[]
    idxs=[]
    k=0
    isFind=False
    for i in range(n):
        for x in itertools.combinations(s,i):
            a=numpy.sum(list(x))
            #print a,x
            if a in sums:
                idd=sums.index(a)
                result=[x,idxs[idd]]
                isFind=True
                break
            sums.append(a)
            idxs.append(x)
        if isFind:
            break


    #print result
    r1=map(str,list(result[0]))
    r2=map(str,list(result[1]))
    
    return " ".join(r1)+"\n"+" ".join(r2)


lines=int(sys.stdin.readline().strip())
line_strs=[]
for i in range(lines):
    line_strs.append(sys.stdin.readline().strip())

p=Pool(24)
#result=p.map(f, line_strs)
result=map(f, line_strs)

for i,r in enumerate(result):
    print "Case #%d:\n%s" % (i+1, r)

