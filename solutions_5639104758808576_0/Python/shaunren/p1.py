#!/usr/bin/python3 -SOO
import math,string,itertools,fractions,re,array,bisect
from heapq import *
from collections import *

for cas in range(1,int(input())+1):
    sm,l = input().strip().split()
    sm = int(sm)
    l = list(map(int,l))
    t = 0
    c = 0
    for i in range(0,sm+1):
        if c<i and l[i]>0:
            t += (i-c)
            c = i
        c += l[i]
    print('Case #%d: %d'%(cas,t))


