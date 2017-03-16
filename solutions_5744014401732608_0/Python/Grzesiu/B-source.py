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

def test():
    B, M = iline()
    
    yield
    
    S = 2**(B-2)
    
    if S < M:
        print 'IMPOSSIBLE'
        return
        
    bonus = (M == S)
    if bonus:
        M = S-1
        
    print 'POSSIBLE'
    print ('0'*B + bin(M)[2:] + ('1' if bonus else '0'))[-B:]
    for i in xrange(2, B+1):
        print '0'*i + '1'*(B-i)
    
        
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

