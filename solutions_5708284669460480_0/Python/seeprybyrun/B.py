#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random
import re
import string

inf = float('inf')

def next_line(filename):
    return f.readline().strip('\n')

def brute_force(keys,target,S):
    total = 0.
    max_bananas = 0
    count = 0
    for x in it.product(keys,repeat=S):
        x = ''.join(x)
        b = 0
        k = x.find(target,0)
        while k >= 0:
            k = x.find(target,k+1)
            b += 1
        total += b
        count += 1
        max_bananas = max(max_bananas,b)
    return max_bananas - total/count
    
    # expected number of occurrences
    product = 1.0
    for i in range(L):
        prob = Pr[target[i]]
        if prob == 0:
            print 'keys =',keys
            print 'target =',target
            return 0.0 # monkey can't finish the job
        product *= Pr[target[i]]
    expected = (S-L+1)*product
    
    offset = L
    # look for max overlap
    for i in range(1,L): # check for overlap between target[:-i] and target[i:]
        if target[:-i] == target[i:]:
            offset = i
        break

    max_bananas = (S-L)/offset + 1

def solve(keys,target,S):
    # compute probabilities
    K = len(keys)
    L = len(target)
    Pr = { c: 1.*keys.count(c)/K for c in target }
    
    # expected number of occurrences
    product = 1.0
    for i in range(L):
        prob = Pr[target[i]]
        if prob == 0:
            print 'keys =',keys
            print 'target =',target
            return 0.0 # monkey can't finish the job
        product *= Pr[target[i]]
    expected = (S-L+1)*product
    
    offset = L
    # look for max overlap
    for i in range(1,L): # check for overlap between target[:-i] and target[i:]
        if target[:-i] == target[i:]:
            offset = i
        break

    max_bananas = (S-L)/offset + 1

##    print 'keys:',keys
##    print 'target:',target
##    print 'S =',S
##    print 'max:',float(max_bananas)
##    print 'expected:',expected

    return max_bananas - expected

infile = sys.argv[1]
f = open(infile,'r')

T = int(next_line(f))
for t in range(T):
    K,L,S = map(int,next_line(f).split())
    keys = next_line(f)
    target = next_line(f)
    print 'Case #{}: {}'.format(t+1,brute_force(keys,target,S))
f.close()
