# -*- coding: utf-8 -*-
"""
Created on Sun May 10 18:43:14 2015

@author: Oliver
"""

def addCoin(s, k, n, v):
    ns = set(s)
    for i in xrange(1, n+1):
        ns = ns.union( set(j+k*i for j in s if j+k*i <= v) )
    return ns
    
def deter(maxn, had, v):
    s = set([0])
    
    for i in had:
        s = addCoin(s, i, maxn, v)
    
    count = 0
    for i in xrange(1, v+1):
        if (i not in s):
            s = addCoin(s, i, maxn, v)
            count += 1
    return count
    
if '__main__' == __name__:
    with open('C-small-attempt0.in', 'rb') as f:
        T = int( f.readline() )
        
        fout = open('result.txt', 'wb')
        
        for i in xrange(T):
            A, B, C = map( int, f.readline().split() )
            L = map( int, f.readline().split() )
            fout.write('Case #%d: %d\n' % (i+1, deter(A, L, C)) )