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
    as_str = lines.next()
    splited = as_str.split()
    A, B = [int(i) for i in splited]
    p = [float(i) for i in lines.next().split()]
    return A, B, p

def mul(a, b):
    return a * b

def solve(case):
    A, B, p = case
    
    if A > 2:
        p_a_minus_2 = reduce(mul, p[:A - 2])
        p_a_minus_1 = p_a_minus_2 * p[A - 2]
        
        p_right = p_a_minus_1 * p[A - 1]
    elif A == 2:
        p_a_minus_2 = 1
        p_a_minus_1 = p[0]
        p_right = p[0] * p[1]
    else: # A == 1
        p_a_minus_2 = p_a_minus_1 = 1
        p_right = p[0]
    
    # keep typing
    p_A = p_right * (B - A + 1) + (1 - p_right) * (B - A + 1 + B + 1)
    
    # 1 back space
    p_B = p_a_minus_1 * (B - A + 3) + (1 - p_a_minus_1) * (B - A + 3 + B + 1)
    # 2 back space
    p_C = p_a_minus_2 * (B - A + 5) + (1 - p_a_minus_1) * (B - A + 5 + B + 1)
    
    #enter right away
    p_D = 1 + (B + 1)
    
    return min([p_A, p_B, p_C, p_D])
 
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
