#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import math

f_input = open(sys.argv[1])
problems = int(f_input.readline().rstrip())
for probnum in xrange(1, problems+1):
    
    C, F, X = map(float, f_input.readline().rstrip().split())

    n = math.floor(X/C-2/F)
    n = 0 if n < 0 else n

    cps = 2+n*F
    time = X/cps + sum([C/(2+F*i) for i in xrange(int(n))])
    print("Case #%i: %f" % (probnum, time))
    
