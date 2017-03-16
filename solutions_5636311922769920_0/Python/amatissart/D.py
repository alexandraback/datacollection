# -*- coding: utf-8 -*-

import sys


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        K,C,S = map(int,f.readline().strip().split())
        res = " ".join(map(str,range(1,K+1)))
        print 'Case #{}: {}'.format(i+1,res)
        
