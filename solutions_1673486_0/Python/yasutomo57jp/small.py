#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import math
import itertools
from multiprocessing import Pool
import numpy


def f(line_str):
    a_str,b_str=line_str[0].split(" ")
    prob_str=line_str[1].split(" ")
    results=0

    a=int(a_str)
    b=int(b_str)
    prob=[float(x) for x in prob_str]

    probs=numpy.ones((a+1,1),dtype=numpy.float)
    nums=numpy.zeros((a+2,a+1),dtype=numpy.int)

    r=b-a

    for i in range(a+1):
        if i==0:
            for j in prob:
                probs[i]*=j
        else:
            for j in prob[:-i]:
                probs[i]*=j
            probs[i]*=(1-prob[-i])

    nums[0,0]=r+1
    nums[0,1:]=[r+1+b+1 for x in probs[1:]]
    nums[a+1]=[1+b+1 for x in probs]

    for i in range(a+1):
        if i==0:continue
        penalty=2*i
        nums[i]=[penalty+r+1 for x in probs]
        for j in range(i+1,a+1):
            nums[i][j]+=b+1

    result=numpy.min(numpy.dot(nums,probs))
    return "%.6f" % (result)

lines=int(sys.stdin.readline().strip())
line_strs=[]
for i in range(lines):
    line_strs.append([sys.stdin.readline().strip(),sys.stdin.readline().strip()])

p=Pool(8)
#result=p.map(f, line_strs)
result=map(f, line_strs)

for i,r in enumerate(result):
    print "Case #%d: %s" % (i+1, r)

