#!/usr/bin/python

import sys, decimal as d, collections as coll, itertools as it, fractions as f



T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    Smax, S = raw_input().split()
    
    Smax = int(Smax)    
    # print >>sys.stderr, 'S: ', S
    S = map(int, S)
        
    res = 0
    summ = S[0]
    for i in xrange(1,Smax+1):
        # print >>sys.stderr, 'i, S[i], summ: ', i, S[i], summ
        if S[i] > 0 and i > summ:
            res += i - summ
            # print >>sys.stderr, 'Added: ', i - summ
            summ = i
        
        summ += S[i]
        
    
    print res
            
    
