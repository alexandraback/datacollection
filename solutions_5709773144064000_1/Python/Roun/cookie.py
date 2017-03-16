#!/usr/bin/env python

from __future__ import print_function
from sys import argv,stdin
import math

with open(argv[1]) if len(argv)>1 else stdin as f:
    num_cases = int(f.readline())
    for i in xrange(num_cases):
        C, F, X = [float(x) for x in f.readline().split()]
        n = math.ceil(X/C-2.0/F-1.0)
        if n < 1:
            t = X/2.0
        else:
            t = X/(2+n*F)
            for k in xrange(int(n)):
                t += C/(2+k*F)
        print('Case #%d: %.7f'%(i+1,t))
