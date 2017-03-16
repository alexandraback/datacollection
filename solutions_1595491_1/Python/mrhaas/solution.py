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
        self.S, self.p, self.scores = data
        
    @time_function    
    def get_solution(self):                
        if self.p == 0:
            return len(self.scores)
        if self.p == 1:
            return len([score for score in self.scores if score > 0])
        return len([score for score in self.scores if score >= 3 * self.p - 2]) + min(self.S, len([score for score in self.scores if score >= 3 * self.p - 4 and score < 3 * self.p - 2]))
            
        


@time_function
def main():
    data = sys.stdin.read().split('\n')    
    n = int(data.pop(0))
    results = {}
    pool = Pool()
    for i in range(1, n + 1):
        l = data.pop(0).split()
        N = int(l.pop(0))
        S = int(l.pop(0))
        p = int(l.pop(0))
        scores = [int(l.pop(0)) for j in range(N)]

        args = (S, p, scores)
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
