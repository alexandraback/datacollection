#!/usr/bin/python
#
# S. Singh
# April 12, 2013

import itertools
import numpy as np
import operator
import sys


divisors = lambda n : set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
subsets = lambda x: list(itertools.chain(*[itertools.combinations(x, ni) for ni in range(1, len(x)+1)]))

def testNumbers(factors, X, i):
    f = factors[:]
    f.pop(i)
    S = [reduce(operator.mul, s, 1) for s in subsets(f)]
    
    for x in X:
        if x not in X:
            return False
    return True
       

def guessNumber(N, M, X):
    factors = []
    for x in X:
        for d in divisors(x):
            if d > 1 and d <= M and d not in factors:
                factors.append(d)
    
    n = 0
    while 1:
        if len(factors) == 0:
            return 0
        elif len(factors) == N:
            return int(''.join(map(str, factors)))
        elif len(factors) < N:
            if n == 0:
                if reduce(operator.mul, factors, 1) < max(X):
                    factors.append(max(X) // reduce(operator.mul, factors, 1))
            else:
                while len(factors) < N:
                    factors.append(factors[-1])
        else:
            for i in xrange(len(factors)):
                if testNumbers(factors, X, i):
                    factors.pop(i)
                    
                    if len(factors) == N:
                        return int(''.join(map(str, factors)))
                    else:
                        break
        
        n += 1


if __name__ == "__main__":
    T = int(sys.stdin.readline())
    
    for i in xrange(1, T + 1):
        R, N, M, K = map(int, sys.stdin.readline().split())
        X = [map(int, sys.stdin.readline().split()) for j in xrange(R)]
        
        print 'Case #%d:' % i
        
        for x in X:
            print guessNumber(N, M, x)
    
    

