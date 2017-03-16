
'''
Created on Apr 12, 2013

@author: herman
'''
import math
import sys
from scipy import misc


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

for i in xrange(trials):
    N,X,Y = [int(x) for x in infile.readline().split()]
    
    side = abs(X)+Y+1
    height = Y+1
    prev_triangle = ((side-2)*(side-1)/2)
    if height < side:
        min_N = prev_triangle + height
    else:
        min_N = ((side)*(side+1)/2)
    max_N = prev_triangle + (side-1) + height
    
    print side,height,prev_triangle,min_N,max_N
    
    if N < min_N:
        result = 0.0
    elif N >= max_N:
        result = 1.0
    else:
        leftover = N - prev_triangle
        if leftover < side:
            M = leftover
            eff_height = height
        else:
            spillover = leftover - side + 1
            M = side - 1 - spillover
            eff_height = height - spillover
        
        print leftover,M,eff_height
        # now we just sum binomial
        configs_without = 0
        for h in xrange(eff_height):
            configs_without += misc.comb(M,h)
        prob_without = float(configs_without)/float(math.pow(2,M))
        result = 1.0 - prob_without

    # print result
    s = "Case #%d: %.10f\n" % (i+1,result)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()