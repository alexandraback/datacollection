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
    s = [int(i) for i in splited[1:]]
    assert int(splited[0]) == len(s)
    return s

def solve(case):
    points = case
    total = sum(points)
    n = len(points)
    results = [0] * n
    ps = sorted([(x, i) for i,x in enumerate(points)])
    
    curr = ps.pop(0)
    allocated = 0.0
    indices = [curr[1]]
    while allocated <= 1.0 and ps:
        next = ps.pop(0)
        if next[0] <= curr[0]:
            indices.append(next[1])
        else:
            delta = float(next[0] - curr[0]) / total
            curr = next
            if (delta * len(indices)) > 1.0 - allocated:
                break
            
            for i in indices:
                results[i] += delta
                
            allocated += delta * len(indices)
            indices.append(next[1])
            
    delta = (1.0 - allocated) / len(indices)
    for i in indices:
        results[i] += delta
             
    return ' '.join(['%f' % (x * 100,) for x in results])
 
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
