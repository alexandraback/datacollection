# -*- coding: utf-8 -*-

import sys

hikers=[]

def parseLine(s):
    line = s.split()
    D,H,M = tuple(map(int,line))
    for i in xrange(H):
        hikers.append((float(360-D)/360*(i+M),i+M))
    
def nb():
    res = 10000000000000000000
    l = len(hikers)
    for i in xrange(l):
        for k in xrange(100):
            total = k
            t = hikers[i][0] + k*hikers[i][1]
            for j in range(i) + range(i+1,l):
                a,b = hikers[j]
                if a >= t:
                    total += 1
                if a + b <= t:
                    total += int(t-a / b)
            if total <= res:
                res = total
    return res
        

filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        hikers = []
        N = int(f.readline())
        for _ in xrange(N):
            parseLine(f.readline())
        res = nb()
        print 'Case #%d: %d' % (i+1,res)
        
