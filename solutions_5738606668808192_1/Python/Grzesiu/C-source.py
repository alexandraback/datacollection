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
import sys

def test():
    N, J = iline()
    
    yield
    
    print
    i = 0
    while J:
      seq = '1' + (('0'*N)+bin(i)[2:])[-(N-2):] + '1'
      divisors = []
      for base in xrange(2,11):
        val = int(seq, base)
        p = 2
        while p*p <= 10000000:
          if val % p == 0:
            divisors.append(p)
            val = None
            break
          p += 1
            
        if val is not None:
           seq = None
           break
      if seq is not None:
        print >>sys.stderr, 'Found one,', J, 'missing'
        print seq, ' '.join(map(str, divisors))
        J -= 1
        
      i += 1
        
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

