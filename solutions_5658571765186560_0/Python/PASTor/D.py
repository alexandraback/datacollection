#!/usr/bin/python

import sys, decimal as d, collections as coll, itertools as it, fractions as f, math



T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    X,R,C = map(int, raw_input().split() )
    
    if (R*C % X != 0) or (X >= 7) or (X > max(R,C)):
        print "RICHARD"
    elif X==1 or X==2:
        print "GABRIEL"
        
    elif ((X >= 3) and (min(R,C) == 1)):
        print "RICHARD"
    elif (X==3):
        print "GABRIEL"
        
    elif (X >= 4) and (min(R,C) == 2):
        print "RICHARD"
    elif (X==4):
        print "GABRIEL"      
        
    else:
        print "GABRIEL"
