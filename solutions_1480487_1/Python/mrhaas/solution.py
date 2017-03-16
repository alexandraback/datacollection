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
        self.points, = data
        
    @time_function    
    def get_solution(self):        
        total = sum(self.points)
        N = len(self.points)
        t = 2*total/N
        N = len([x for x in self.points if x <= t])
        total2 = total - sum([x for x in self.points if x > t])
        
        result = []
        
        for p in self.points:
            m = (float(total+total2)/N - p)/total
            result.append(max(0,m))
        
        return ' '.join(['%.6f' % (r*100,) for r in result])

@time_function
def main():
    data = sys.stdin.read().split('\n')    
    n = int(data.pop(0))
    results = {}
    pool = Pool()
    for i in range(1, n + 1):
        line = data.pop(0).split()
        c = int(line.pop(0))
        points = [int(line.pop(0)) for p in range(c)]        
        args = (points,)
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
