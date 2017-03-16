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
        self.A, self.B = data
        
    @time_function    
    def get_solution(self):
        sols = {}
                
        for n in range(self.A, self.B + 1):
            s_n = str(n)
            
            for l in range(1, len(s_n)):
                if s_n[l] == "0" or int(s_n[l] < n):
                    continue
                s_m = s_n[l:] + s_n[:l]
                m = int(s_m)
                if m > n and m <= self.B:
                    if not n in sols:
                        sols[n] = set()
                    sols[n].add(m)
        return sum([len(ms) for n, ms in sols.items()])

@time_function
def main():
    data = sys.stdin.read().split('\n')    
    n = int(data.pop(0))
    results = {}
    pool = Pool()
    for i in range(1, n + 1):
        l = data.pop(0).split()
        A = int(l.pop(0))
        B = int(l.pop(0))
        args = (A, B)
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
