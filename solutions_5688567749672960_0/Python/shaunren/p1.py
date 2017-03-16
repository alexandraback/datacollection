#!/usr/bin/python3 -SOO
import math,string,itertools,fractions,re,array,bisect
from heapq import *
from collections import *

d = [float('inf') for _ in range(1000001)]
d[1] = 1
for i in range(1,1000000):
    d[i+1] = min(d[i+1], d[i]+1)
    kr = int(str(i)[::-1].lstrip('0'))
    if kr<=1000001: d[kr] = min(d[kr], d[i]+1)

for cas in range(1,int(input())+1):
    n = int(input())
    
    print('Case #%d: %d'%(cas,d[n]))
            
