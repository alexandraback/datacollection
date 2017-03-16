# -*- coding: utf-8 -*-

import sys
    
def solve(n):
    m = dict()
    if n == 0:
        return 'INSOMNIA'
    else:
        orig = n
        while True:
            for i in str(n):
                m[i] = m.get(i, 0) + 1
            if len(m) == 10:
                return n
            n += orig


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        n = int(f.readline())
        res = solve(n)
        print 'Case #{}: {}'.format(i+1,res)
        
