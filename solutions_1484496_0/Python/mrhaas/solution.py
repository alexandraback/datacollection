#!/usr/bin/env python
import sys, os
from multiprocessing import Pool

DEBUG = os.getenv("DEBUG") == "1"

def time_function(func):    
    def wrapped_func(*args, **kwargs):
        from time import time
        start = time()
        sys.stderr.write('Function %s started\n' % (func.__name__,))
        res = func(*args, **kwargs)
        sys.stderr.write('Function %s finished in %.6fs\n' % (func.__name__, time() - start))
        return res
    wrapped_func.__doc__ = func.__doc__
    return wrapped_func

def get_subsets(ns, length):
    if length == 0:
        yield []
    else:
        for i in range(len(ns) - length + 1):
            for n in get_subsets(ns[i+1:], length - 1):
                yield [ns[i]] + n

class Problem(object):
    def __init__(self, data):
        self.ns, = data
        
    
    @time_function    
    def get_solution(self):
        subsets = {}
        for i in range(1,11):
            for subset in get_subsets(self.ns, i):
                s = sum(subset)
                if s in subsets:
                    return '\n%s\n%s' % (' '.join([str(m) for m in subset]), ' '.join([str(m) for m in subsets[s]]))
                subsets[s] = subset
        return '\nImpossible'

@time_function
def main():
    data = sys.stdin.read().split('\n')    
    n = int(data.pop(0))
    results = {}
    pool = Pool()
    for i in range(1, n + 1):
        line = data.pop(0).split()
        c = int(line.pop(0))
        ns = [int(line.pop(0)) for x in range(c)]
        args = (ns,)
        if DEBUG:
            results[i] = Problem(args).get_solution()
        else:          
            results[i] = pool.apply_async(Problem(args).get_solution)
    pool.close()
    pool.join()
    
    for i in sorted(results):
        res = results[i]
        if not DEBUG:
            res = res.get()
        print "Case #%d: %s" % (i, res)   
    
if __name__ == '__main__':
    from doctest import testmod
    print >> sys.stderr, testmod()
    main()
