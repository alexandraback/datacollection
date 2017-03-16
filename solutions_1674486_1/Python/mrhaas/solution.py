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

class Problem(object):
    def __init__(self, data):
        self.parentdata, = data
        self.childrendata = {}
        
        for i, parents in self.parentdata.iteritems():
            for parent in parents:
                if not parent in self.childrendata:
                    self.childrendata[parent] = []
                self.childrendata[parent].append(i)
        
    def get_paths(self, start):
        children = self.childrendata.get(start, False)
        
        yield [start]
        for child in self.childrendata.get(start, []):
                for path in self.get_paths(child):
                    yield [start] + path
        
    def get_roots(self):
        for i, parents in self.parentdata.iteritems():
            if len(parents) == 0:
                yield i
    
    @time_function    
    def get_solution(self):        
        paths = {}
        
        for root in self.get_roots():
            for path in self.get_paths(root):
                if len(path) >= 2:
                    h = (path[0], path[-1])
                    if h in paths and path <> paths[h]:
                        return 'Yes'
                    paths[h] = path
            
        return 'No'
        

@time_function
def main():
    data = sys.stdin.read().split('\n')    
    n = int(data.pop(0))
    results = {}
    pool = Pool()
    for i in range(1, n + 1):
        C = int(data.pop(0))
        d = {}
        for c in range(1, 1 + C):
            line = data.pop(0).split()
            I = int(line.pop(0))
            inherits = [int(line.pop(0)) for _ in range(I)]
            d[c] = inherits
            
        args = (d,)
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
