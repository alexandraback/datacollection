#!/usr/bin/env python

from sys import stdin
import numpy as np

ntest = input()

for test in xrange(ntest):
    n, m = [int(i) for i in stdin.readline().strip().split(' ')]
    lawn = np.zeros((n, m), dtype=np.int)
    for i in xrange(n):
        lawn[i, :] = [int(c) for c in stdin.readline().strip().split(' ')]
    
    if (np.minimum(lawn.max(0), lawn.max(1)[:,np.newaxis]) == lawn).all():
        result = 'YES'
    else:
        result = 'NO'
    
    print "Case #{}: {}".format(test+1, result)

