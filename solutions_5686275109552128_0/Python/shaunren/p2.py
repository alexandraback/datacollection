#!/usr/bin/python3 -SOO
import math,string,itertools,fractions,re,array,bisect
from math import ceil
from heapq import *
from collections import *

for cas in range(1,int(input())+1):
    n = int(input())
    l = list(map(int,input().strip().split()))
    heapify(l)
    t = 0
    mx = max(l)
    best = mx
    for m in range(1,mx):
        t = 0
        for x in l:
            k = int(ceil(x/(m+1)))
            while k>0 and ((x+k-1)//k <= m): k -= 1
            t += k
        best = min(best,t+m)
    
    print('Case #%d: %d'%(cas,best))
        
    
