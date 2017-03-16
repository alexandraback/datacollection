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
            print "###", args
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
    as_str = lines.next().strip()
    n = int(as_str)
    levels = []
    for i in xrange(n):
        a, b = [int(i) for i in lines.next().split()]
        levels.append((a, b))
        
    return n, levels

def solve(case):
    n, levels = case
    
    num_levels = 0
    num_stars = 0
    
    while levels:
        
        # check for 2-star
        found = False
        for m in levels:
            if num_stars >= m[-1]:
                num_levels += 1
                num_stars += len(m)
                levels.remove(m)
                m = m[:-1]
                found = True
                break
        if found:
            continue
        
        with_indices = [(m, i) for i,m in enumerate(levels)]
        passing = [(m, i) for m, i in with_indices if num_stars >= m[0]]
        if not passing:
            return 'Too Bad'
        
        passing.sort()
        next_level = passing[-1]
        m, i = next_level
        num_levels += 1
        num_stars += 1
        levels.pop(i)
        m = m[1:]
        assert m
        levels.append(m)
    return num_levels
        
        
 
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
