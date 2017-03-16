import sys
from math import *
import decimal
decimal.getcontext().prec = 60
inp = sys.stdin

T = int(inp.readline())

for testCase in xrange(1,T+1):
    r, t = map(lambda x: int(x), inp.readline().split(" "))
    paintUsed = 0
    newT = 0
    if r % 2 == 1:
        newT = 2*t + (r*(r-1))
        rings = int((decimal.Decimal(1+4*newT).sqrt() - 1)/2)
        rings -= (rings % 2)
        rings -= (r-1)
        ringCount = (rings)/2
   
    if r % 2 == 0:
        newT = 2*t + (r*(r-1))
        rings = int((decimal.Decimal(1+4*newT).sqrt() - 1)/2)
        rings += (rings % 2)
        rings -= r
        ringCount = (rings)/2
   
    print "Case #{}: {}".format(testCase, ringCount)
            
        
