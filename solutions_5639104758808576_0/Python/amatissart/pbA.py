# -*- coding: utf-8 -*-

import sys

def parseLine(s):
    line = s.split()
    return map(int,line[1])
    
def friends(l):
    res = 0
    tot = 0
    for i,n in enumerate(l):
        if n>0 and tot < i:
            res += i-tot
            tot = i
        tot += n
    return res
         


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        l = parseLine(f.readline())
        res = friends(l)
        print 'Case #%d: %d' % (i+1,res)
        
