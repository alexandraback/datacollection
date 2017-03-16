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

sys.modules["storage"] = __mod = imp.new_module("storage")
exec """
import shelve, sys

def store(name, version=None):
  def decorator(callable):
    try:
      storage = shelve.open('{}.shelve'.format(name))
      if version is not None and storage.has_key('version') and storage['version'] == version:
        print >>sys.stderr, \"Loading {}...\".format(callable.__name__)
        object = storage['object']
      else:
        print >>sys.stderr, \"Calculating {}...\".format(callable.__name__)
        storage['object'] = object = callable()
        storage['version'] = version
      print >>sys.stderr, \"Done\"
      return object
    finally:
      storage.close()
  return decorator""" in vars(__mod)

#!/usr/bin/python

from utils import iline
from storage import store

N = 1000000

@store('A', 1)
def data():
    def calculate(x):
        if x == 0:
            return 'INSOMNIA'
            
        nums = set()
        for y in xrange(x, 1000000000, x):
            nums |= set(str(y))
            if len(nums) == 10:
                return y
            
    return map(calculate, xrange(0, N+1))
            
def test():
    n, = iline()
    
    yield
    
    print data[n]
        
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

