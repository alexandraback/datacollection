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
    n = int(splited[0])
    num = [int(i) for i in splited[1:]]
    assert len(num) == n
    return num

def set_iterator_aux(index, nums):
    if index == len(nums):
        yield []
        return
    
    for i in set_iterator_aux(index + 1, nums):
        yield [nums[index]] + i
        yield i
        
def set_iterator(nums):
    for i in set_iterator_aux(0, nums):
        if i:
            yield i
            

def solve(case):
    nums = case
    
    sums = {}
    sets = []
    
    i = 0
    for s in set_iterator(nums):
        curr = sum(s)
        if curr in sums:
            other = sets[sums[curr]]
            print '$$$$', s, other
            return (' '.join(['%d' % y for y in s]), 
                    ' '.join(['%d' % y for y in other]))
        else:
            sums[curr] = i
        sets.append(s)
        i += 1
        print 'i %d\r' % (i,),
        
    return None, None
 
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
            out_line = 'Case #%d:' % (i,)
            print >> fout, out_line
            first, second = solve(case)
            if first is None:
                print >> fout, 'Impossible'
            else:
                print >> fout, first
                print >> fout, second
            if debug:
                print out_line
            
            total = time.time() - start
            if trace:
                print >> sys.stderr, ('remaining: %.2f seconds' %  
                                      ((n - i) * (total / i),))

if __name__ == '__main__':
    main()
