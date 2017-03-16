import imp, sys

sys.modules["utils"] = __mod = imp.new_module("utils")
exec """#!/usr/bin/python

from itertools import chain, repeat, izip

def line(*args):
	L = raw_input().strip().split()
	L = izip( L, chain( args, repeat(str) ) )
	return [ type(data) for data, type in L ]	
	
def iline(): return map( int, raw_input().strip().split() )
def fline(): return map( float, raw_input().strip().split() )""" in vars(__mod)

#!/usr/bin/python

from utils import iline
from fractions import gcd
from collections import defaultdict

def test():
    A, B, C, K = iline()
    
    yield
    
    triples = set()
    pairs = defaultdict(int)
    
    while True:
        n = len(triples)
        for a in xrange(A):
            a = (a+len(triples))%A
            for b in xrange(B):
                b = (b+len(triples))%B
                for c in xrange(C):
                    c = (c+len(triples))%C
                    
                    if (a,b,c) in triples or pairs[('ab',a,b)] >= K or pairs[('ac',a,c)] >= K or pairs[('bc',b,c)] >= K:
                        continue
                        
                    triples.add((a,b,c))
                    pairs[('ab',a,b)] += 1
                    pairs[('ac',a,c)] += 1
                    pairs[('bc',b,c)] += 1
    
        if len(triples) == n:
            break
            
    print len(triples)
    for a, b, c in triples:
        print a+1, b+1, c+1
        
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

