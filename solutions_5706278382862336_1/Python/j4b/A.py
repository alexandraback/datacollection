#!/usr/bin/python

import sys
import functools
import operator
import math
from itertools import chain, combinations
from heapq import heappop, heappush, _siftup

from fractions import gcd

def isPowerOfTwo(k):
    while k % 2 == 0:
        k = k / 2
    if k > 1:
        return False
    else:
        return True

def solve(p, q):
    if not isPowerOfTwo(q):
        return "impossible"
    #elif math.log(q,2) > 40:
    #    return "impossible"
    else:
        k = 1
        g = 0
        while p*k < q:
            k = k * 2
            g += 1
        return g
        
            
        
def main():
    for i in range(int(raw_input())):
        [p, q] = [int(x) for x in raw_input().split('/')]
        g = gcd(p, q)
        result = solve(p/g, q/g)
        print ("Case #%s: %s" % (i+1, result))

if __name__ == '__main__':
    main()
