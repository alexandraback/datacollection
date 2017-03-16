#! /usr/bin/env python

from sys import stdin
import sys
import numpy as np

sieve = np.ones(10000, dtype=np.bool)
sieve[:2] = False
for i in xrange(2, 101):
    if sieve[i]:
        sieve[i*i::i] = False
primes = np.nonzero(sieve)[0]

def findDivisor(n):
    for d in primes:
        if d >= n:
            return False
        if n % d == 0:
            return d
    return False

def check(coin):
    ans = []
    for base in xrange(2, 11):
        n = int(coin, base)
        d = findDivisor(n)
        if d:
            ans.append(d)
        else:
            return False
    return ans

ntest = input()

for test in xrange(ntest):
    N, J = [int(i) for i in stdin.readline().split()]
    print "Case #{}:".format(test + 1)
    for cur in xrange(2**(N-1) + 1, 2**N, 2):
        if J == 0:
            break
        divisors = check("{:b}".format(cur))
        if divisors:
            print "{:b}".format(cur), ' '.join(str(i) for i in divisors)
            J -= 1

