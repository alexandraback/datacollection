# -*- coding: utf-8 -*-

import sys
from decimal import *

if __name__ == '__main__':
    tests = int(sys.stdin.readline())
    getcontext.prec = 12
    for test in xrange(1, tests+1):
        line = sys.stdin.readline().split()
        a, b = int(line[0]), int(line[1])

        line = sys.stdin.readline().split()
        p = [Decimal(x) for x in line]

        r = []
        r.append(b+2)

        q = 1
        j = a
        while j > 0:
            t0 = b-(a-j)+1+j
            t1 = t0+b+1
            r.append(t0*q+t1*(1-q))
            j -= 1
            q *= p[a-j-1]
        t0 = b-a+1
        t1 = t0+b+1
        r.append(t0*q+t1*(1-q))        
        
        print "Case #%d: %0.6f" % (test, min(r))
