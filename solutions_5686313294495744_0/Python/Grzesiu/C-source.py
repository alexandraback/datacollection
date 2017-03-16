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

from utils import iline, line
from collections import defaultdict
import sys

def test():
    n, = iline()
    topics = { tuple(line()) for i in xrange(n) }
    
    yield
    
    first = { a for a,b in topics }
    second = { b for a,b in topics }
    
    answer = 0
    
    for mask in xrange(2**n):
        mask = ('0'*n + bin(mask)[2:])[-n:]
        
        first_ = { a for (a,b), m in zip(topics, mask) if m == '1' }
        second_ = { b for (a,b), m in zip(topics, mask) if m == '1' }
        
        if first_ == first and second_ == second:
            answer = max(answer, mask.count('0'))
            
    print answer
        
                
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

