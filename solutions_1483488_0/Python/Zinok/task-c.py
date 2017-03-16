#!/usr/bin/env python2.6

import sys

# get number of cases
num = int(sys.stdin.readline())

# read cases data
cases = sys.stdin.readlines()

# process cases
for j in xrange(len(cases)):
    case = [int(v) for v in cases[j].split(' ')]
    
    # to simplify - give names
    a = case[0]
    b = case[1]
    digits = len('%s' % a)
    res = 0
    
    # iterate a to b
    for x in xrange(a, b+1):
        xs = str(x)
        for i in xrange(1, digits):
            xn = int('%s%s' % (xs[-i:], xs[:-i]))
            
            # if number of same digits (111, 2222, etc)
            if x == xn:
                break
                
            # if new number is within range
            if xn >= a and xn <= b:
                res += 1

    # results are doubled
    res = res / 2
                
    print "Case #%d: %d" % (j+1, res)