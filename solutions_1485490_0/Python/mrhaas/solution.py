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
        self.boxes, self.toys = data
        
    def get_combs(self, toys, boxes):
        res = 0
        
        if len(toys) == 0 or len(boxes) == 0:
            return 0
        
        nt, t = toys[0]
        nb, b = boxes[0]
        
        if t == b:
            res = min(nb, nt)
            
            if res == nt:
                toys.pop(0)
            else:
                toys[0] = (nt - res, t)
            
            if res == nb:
                boxes.pop(0)
            else:
                boxes[0] = (nb - res, b)
            return res + self.get_combs(toys[:], boxes[:])
        return res + max(self.get_combs(toys[1:], boxes[:]), self.get_combs(toys[:], boxes[1:]), self.get_combs(toys[1:], boxes[1:]))

    @time_function    
    def get_solution(self):        
        return self.get_combs(self.toys, self.boxes)

@time_function
def main():
    data = sys.stdin.read().split('\n')    
    n = int(data.pop(0))
    results = {}
    pool = Pool()
    for i in range(1, n + 1):
        line = data.pop(0).split()
        N = int(line.pop(0))
        M = int(line.pop(0))
        line = data.pop(0).split()
        boxes = [(int(line.pop(0)), int(line.pop(0))) for _ in range(N)]
        
        line = data.pop(0).split()
        toys = [(int(line.pop(0)), int(line.pop(0))) for _ in range(M)]
        
        args = (boxes, toys)
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
