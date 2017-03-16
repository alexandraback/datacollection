from __future__ import print_function, division
import sys
import array
import re
from heapq import heappush, heappop
from fractions import gcd
from future_builtins import filter, map, zip
#import numpy as np
DD=print
r=0
t=0
def used(n):
    return 2*n*(n+1)+n*(2*r-3)

TOTAL = int(raw_input())
for case in xrange(1,TOTAL+1):
    r, t = map(int, raw_input().split())
    low=0
    hi=1
    #for i in xrange(0,5):
        #print(used(i))
    while used(hi) <= t:
        low = hi
        hi=hi*2

    while low<hi:
        mid = (hi + low)//2
        v = used(mid)
        #print("aaa", v, low, hi, mid)
        if v == t:
            low=mid
            break
        elif v < t:
            low=mid
        else:
            hi=mid
        if low+1==hi:
            break

    print('Case #{0}: {1}'.format(case, low))
