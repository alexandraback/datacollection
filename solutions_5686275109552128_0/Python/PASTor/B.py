#!/usr/bin/python

import sys, decimal as d, collections as coll, itertools as it, fractions as f, bisect as b



T = int(raw_input())
tt = max(T/10, 1)

for c in xrange(T):
    print 'Case #{}:'.format(c+1),
    if c % tt == 0:
        print >>sys.stderr, 'Solving: ', (c+1)*100/T, '%'
    
    d = int(raw_input())
    p = sorted( map(int, raw_input().split()) )
       
    print >>sys.stderr, 'p: ', p
       
    res = p[-1]
    time = 0
    add = []
    
    half = p[-1] - p[-1] / 2
    ind = b.bisect(p, half)
    
    while half != 1 and half > len(p) - ind:
        add = []
        for i in xrange(len(p)-1, ind-1, -1):
            time += 1
            add += [ p[i]/2, p[i] - p[i]/2 ]
            if i==0:
                res = min(res, time + half)
                # print >>sys.stderr, 'res = min(res, time + half): ', res, time, half
            else:
                res = min(res, time + max(p[i-1], half))
                # print >>sys.stderr, 'res = min(res, time + p[i-1]): ', res, time, p[i-1], i
            
        p = sorted( p[:ind] + add )
        
        half = p[-1] - p[-1] / 2
        ind = b.bisect(p, half)
        
        print >>sys.stderr, 'p, half, ind, time: ', p, half, ind, time
            
    
    for i in xrange(len(p)-1, ind-1, -1):
        time += 1
        # add += [ p[i]/2, p[i] - p[i]/2 ]
        if i==0:
            res = min(res, time + half)
            # print >>sys.stderr, 'Last. res = min(res, time + half): ', res, time, half
        else:
            res = min(res, time + max(p[i-1], half))
            # print >>sys.stderr, 'Last. res = min(res, time + p[i-1]): ', res, time, p[i-1], i
    
    print >>sys.stderr, 'Result: ', res
    
    print res
            
    
