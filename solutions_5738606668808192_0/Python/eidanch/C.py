# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 02:37:39 2016

@author: Eidan Cohen
"""

import random
from math import gcd

 
_mrpt_num_trials = 8 # number of bases to test
 
def is_probable_prime(n):
    assert n >= 2
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
        return False
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n-1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2**s * d == n-1)
 
    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True # n is definitely composite
 
    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False
 
    return True # no base tested showed n as composite

def pollard_rho(n):
    if is_probable_prime(n):
        return None
    lst = [random.randint(1,n-1)]
    while True:
        y = random.randint(1,n-1)
        for x in lst:
            z = abs(x - y)
            d = gcd(z,n)
            if d > 1 and d < n:
                return d
        lst.append(y)

def jamcoin(coin):
    divisors = []
    for base in range(2,11):
        x = int(coin, base)
        d = pollard_rho(x)
        if d is None:
            return None
        assert x % d == 0
        divisors.append(d)
    return divisors
    
def solve(N,J):
    n = N - 2
    j = 0
    for i in range(0,pow(2,n)):
        r = bin(i)[2:]
        coin = '1' + (n - len(r))*'0' + str(r) + '1'
        divisors = jamcoin(coin)
        if divisors is None:
            continue
        print(coin, ' '.join(map(str,divisors)))
        j += 1
        if j == J:
            return
            
if __name__ == '__main__':
    print("Case #1:")
    solve(16, 50)
