#!/usr/bin/python
#
# S. Singh
# April 12, 2013

from decimal import *
import numpy as np
import sys

getcontext().prec = 40


def numRings(r, t):
    return(Decimal(4*r*r - 4*r + 8*t + 1).sqrt() - 2*r - 3) // 4 + 1

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    
    for i in xrange(1, T + 1):
        r, t = map(int, sys.stdin.readline().strip().split())
        print 'Case #%d:' % i, numRings(r, t)
    
    

