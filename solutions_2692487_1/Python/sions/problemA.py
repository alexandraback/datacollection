import sys
import os
import math
import fractions
import functools
import time

class memoized(object):
    '''Decorator. Caches a function's return value each time it is called.
    If called later with the same arguments, the cached value is returned 
    (not reevaluated).
    '''
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        try:
            return self.cache[args]
        except KeyError:
            value = self.func(*args)
            self.cache[args] = value
            return value
        except TypeError:
            # uncachable -- for instance, passing a list as an argument.
            # Better to not cache than to blow up entirely.
            return self.func(*args)
    def __repr__(self):
        '''Return the function's docstring.'''
        return self.func.__doc__
    def __get__(self, obj, objtype):
        '''Support instance methods.'''
        return functools.partial(self.__call__, obj)
  
def case_iterator(path):
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())
        
        yield n
        
        for i in range(1, 1 + n):
            yield i, read_case(lines)
            
def read_case(lines):
    as_str = lines.next()
    splited = as_str.split()
    A, N = [int(i) for i in splited]
    motes = [int(i) for i in lines.next().split()]
    assert len(motes) == N
    return A, motes

@memoized
def recurse(A, motes):
    idx = 0
    for i in motes:
        if A > i:
            A += i
            idx += 1
        else:
            break
        
    motes = tuple(motes[idx:]) 
    if not motes:
        return 0
    
    if A > 1:
        return 1 + min(recurse(A + A - 1, motes),
                       recurse(A, tuple(motes[:-1])))
    else:
        return 1 + recurse(A, tuple(motes[:-1]))

def solve(case):
    A, motes = case
    
    motes = tuple(sorted(motes))
    
    return recurse(A, motes)
    
 
trace = False 
debug = True
    
def main():
    try:
        path, = sys.argv[1:]
    except:
        sys.exit('usage: %s <input file>' % (sys.argv[0],))
    
    iterator = case_iterator(path)
    n = iterator.next()

    outpath = os.path.splitext(path)[0] + '.out'

    with file(outpath, 'wt') as fout:
        start = time.time()
        for i, case in iterator:
            out_line = 'Case #%d: %s' % (i, solve(case))
            print >> fout, out_line
            if debug:
                print out_line
            
            total = time.time() - start
            if trace:
                print >> sys.stderr, ('remaining: %.2f seconds' %  
                                      ((n - i) * (total / i),))

if __name__ == '__main__':
    main()
