#!/usr/bin/env python3

import bisect
import math
import sys
from prime import PRIMES

bases = tuple(range(2, 11))
didWarning = False

def getPrimes(n):
    global didWarning
    maxPrime1 = int(math.sqrt(n))
    i = bisect.bisect(PRIMES, maxPrime1)
    if not didWarning and i == len(PRIMES):
        print('You may need more primes', file=sys.stderr)
        didWarning = True
    return PRIMES[:i]

def findFactor(n, factors):
    for factor in factors:
        if n % factor == 0:
            return factor

def findJamcoinFactors(s):
    factors = []
    for base in bases:
        n = int(s, base)
        primes = getPrimes(n)
        factor = findFactor(n, primes)
        if factor is None:
            return None
        factors.append(factor)
    return factors

def solve(N, J):
    retval = []
    for i in range(2**(N-2)):
        s = '1{0:0{1}b}1'.format(i, N-2)
        factors = findJamcoinFactors(s)
        if factors is not None:
            retval.append([s] + factors)
            if len(retval) == J:
                break
    return retval

def main():
    T = int(input())
    for i in range(1, T+1):
        N, J = [int(x) for x in input().split()]
        l = solve(N, J)
        print('Case #{0}:'.format(i))
        for n in l:
            print(*n)

if __name__ == '__main__':
    main()
