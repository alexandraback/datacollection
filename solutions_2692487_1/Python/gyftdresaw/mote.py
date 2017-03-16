
'''
Created on Apr 12, 2013

@author: herman
'''
import math
import sys

infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

for i in xrange(trials):
    S,N = [int(x) for x in infile.readline().split()]
    motes = [int(x) for x in infile.readline().split()]
    
    motes.sort()
    
    if S == 1:
        result = N
    else:
        surpass = [0 for x in xrange(N)]
        def to_surpass(s,nexts):
            # print s,nexts
            k = 0
            while (s <= nexts):
                s += s-1
                k += 1
            return (s+nexts,k)
        curr_size = S
        for j in xrange(N):
            (next_size,k) = to_surpass(curr_size,motes[j])
            surpass[j] = k
            curr_size = next_size
            
        # print surpass
        last_best = 0
        curr_best = 0
        for j in xrange(N-1,-1,-1):
            curr_best = min(N-j,surpass[j]+last_best)
            last_best = curr_best
        result = curr_best
    # print result
    s = "Case #%d: %d\n" % (i+1,result)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()