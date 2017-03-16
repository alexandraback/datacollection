#!/usr/bin/python
#
# S. Singh
# April 12, 2013

import itertools
import numpy as np
import sys


divisors = lambda n : set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

def guessNumber(N, M, X):
    factors = []
    for x in X:
        for d in divisors(x):
            if d > 1 and d <= M and d not in factors:
                factors.append(d)
    
    if len(factors) == 0:
        return 0
    elif len(factors) == N:
        return int(''.join(map(str, factors)))
    elif len(factors) < N:
        while len(factors) < N:
            factors.append(factors[-1])
        return int(''.join(map(str, factors)))
    else:
        if 2 in factors and 4 in factors:
            factors.remove(2)
        return int(''.join(map(str, factors)))


if __name__ == "__main__":
    T = int(sys.stdin.readline())
    
    for i in xrange(1, T + 1):
        R, N, M, K = map(int, sys.stdin.readline().split())
        X = [map(int, sys.stdin.readline().split()) for j in xrange(R)]
        
        print 'Case #%d:' % i
        
        for x in X:
            print guessNumber(N, M, x)
    
    

