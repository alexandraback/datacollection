'''
Created on 06 May 2012

@author: dirk-b
'''

import math

inp = open('data/B-small-attempt1.in', 'r')
out = open('data/B-small-attempt1.out', 'w')

T = int(inp.readline())
for t in xrange(1, T + 1):
    print 't', t
    D, N, A = inp.readline().split()
    print D, N, A
    D = float(D)
    N = int(N)
    A = int(A)
    tx = []
    keepAdding = True
    
    for i in xrange(N):
        ti, x = map(float, inp.readline().split())
        print ti, x
        
        if x == D and keepAdding:
            keepAdding = False
            tx.append((ti, x))
            
        if x > D and keepAdding:
            keepAdding = False
            if ti == 0:
                tx.append((ti, x))
            else:
                # calculate when he crossed the line
                dt = ti - tx[ -1][0]
                ds = x - tx[ -1][1]
                v = ds / dt # how fast he is going
                timeCrossed = (D - tx[-1][1]) / v + tx[-1][0] 
                tx.append((timeCrossed, D))
                
        if keepAdding:
            tx.append((ti, x))
            
            
    a_i = map(float, inp.readline().split())
    
    out.write("Case #%d:\n" % t)
    print "Case #%d:\n" % t
    for a in a_i:
        time = 0
        v = 0
        d = 0
        for i in xrange(1, len(tx)):
            dt = tx[i][0] - tx[i - 1][0]
            ds = (tx[i][1] - tx[i - 1][1])
            maxV = ds / dt # how fast he is going
            maxD = v * dt + 0.5 * a * dt * dt # how far we can go
            
            if d + maxD > tx[i][1]: # went too far, but right on his tail
                #print 'too far'
                v = maxV
                d = tx[i][1]
                time += dt
            else:
                #print 'lacking'
                d += maxD
                v = v + a * dt
                time += dt
        
        if d >= D: # right on his tail when we get there
            out.write("%.8f\n" % tx[-1][0])
        else: # free the last bit
            ds = D - d # need to go this far
            tn = (math.sqrt(v * v + 2 * a * ds) - v) / a
            out.write("%.8f\n" % (tx[-1][0] + tn))

inp.close()
out.close()
