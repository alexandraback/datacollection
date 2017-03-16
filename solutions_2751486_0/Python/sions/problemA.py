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
    assert len(splited) == 2
    return splited[0], int(splited[1])

letters = [chr(i) for i in xrange(ord('a'), ord('z') + 1)]
consonants = set([i for i in letters if i not in ('a', 'e', 'i', 'o', 'u')])

def solve(case):
    s, n = case
    total = 0
    next_start = 0
    for i in xrange(len(s) - (n - 1)):
        x = set(s[i:i+n])
                
        if x.issubset(consonants):
            total += (i - next_start + 1) * (len(s) - i - (n - 1))
            next_start = i + 1
    
    return total
    
 
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
