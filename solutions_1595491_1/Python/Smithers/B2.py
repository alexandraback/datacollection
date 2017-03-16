#!/usr/bin/env python

# Problem B. Dancing With the Googlers
# Part II - Compute the final result in Python

t = int(raw_input())
for c in xrange(1, t+1):
    n, s, p = [int(x) for x in raw_input().split()]
    values = raw_input().split()
    values = [(2 if int(x.split(',')[0]) >= p else 1 if int(x.split(',')[1]) >= p else 0) for x in values]
    
    result = sum([(1 if x==2 else 0) for x in values]) + min(sum([(1 if x==1 else 0) for x in values]), s)
    print "Case #" + str(c) + ": " + str(result)
