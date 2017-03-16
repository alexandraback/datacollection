#!/usr/bin/python
# -*- coding: iso-8859-1 -*-

import sys
import math

def iterate(A, sizes, i, op):
    if i == len(sizes)-1:
        if A> sizes[i]:
            return op
        else:
            return op+1
    if A> sizes[i]:
        return iterate(A+sizes[i], sizes, i+1, op)
    else :
        if A == 1:
            return len(sizes)
        return min(iterate(2*A-1, sizes, i, op+1), op + len(sizes)-i)

with open(sys.argv[1], 'r') as f:

    line = f.readline()
    T = int(line)
    for k in range(T):
        line = f.readline()
        A, N = [int(val) for val in line.split()]
        line = f.readline()
        sizes = [int(val) for val in line.split()]
        sizes.sort()
        print("Case #"+str(k+1)+": "+str(iterate(A, sizes, 0, 0)))
          
