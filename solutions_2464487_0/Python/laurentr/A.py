#!/usr/bin/python
# -*- coding: iso-8859-1 -*-

import sys
import math


def dichotomy(r, t):
    inf = 0
    sup = int(1.0e18+1)
    while (sup - inf >1): 
        mid = (inf + sup)/2
        area = (1+mid)*(2*r+1) + 2*mid*(mid+1)
        if  area == t:
            inf = mid
            break
        elif area < t:
            inf = mid            
        else:
            sup = mid
    return inf

with open(sys.argv[1], 'r') as f:

    line = f.readline()
    T = int(line)
    for k in range(T):
        line = f.readline()
        r, t = [int(val) for val in line.split()]
        print("Case #"+str(k+1)+": "+str(1+dichotomy(r, t)))
          
