#!/usr/bin/python

import sys, math
from decimal import *

if len(sys.argv) != 2:
    print "Usage: ./pta <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)

getcontext().prec = 50
data = fin.readlines()
ntests = int(data[0].strip())
for i in range(1,ntests+1):
    info = data[i].strip().split()
    r = int(info[0])
    t = int(info[1])
    a = Decimal(2)
    b = Decimal(2*r-1)
    c = Decimal(-1*t)
    ringCnt =(-1*b+(b**2-4*a*c).sqrt())/(2*a)
    print "Case #%d: %d"%(i,ringCnt)

sys.exit(0)
