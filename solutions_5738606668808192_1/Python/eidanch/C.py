# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 02:37:39 2016

@author: Eidan Cohen
"""

import random
from math import gcd

 
_mrpt_num_trials = 5 # number of bases to test
 
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
        r = 1
        for i in range(s):
            if pow(a, r * d, n) == n-1:
                return False
            r *= 2
        return True # n is definitely composite
 
    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False
 
    return True # no base tested showed n as composite

from threading import Thread
import functools

def timeout(timeout):
    def deco(func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            res = [Exception('function [%s] timeout [%s seconds] exceeded!' % (func.__name__, timeout))]
            def newFunc():
                try:
                    res[0] = func(*args, **kwargs)
                except (Exception, e):
                    res[0] = e
            t = Thread(target=newFunc)
            t.daemon = True
            try:
                t.start()
                t.join(timeout)
            except (Exception, je):
                raise je
            ret = res[0]
            if isinstance(ret, BaseException):
                raise ret
            return ret
        return wrapper
    return deco   
       
@timeout(2)
def pollard_brent(n):
    if n % 2 == 0: return 2
    if n % 3 == 0: return 3

    y, c, m = random.randint(1, n-1), random.randint(1, n-1), random.randint(1, n-1)
    g, r, q = 1, 1, 1
    while g == 1:
        x = y
        for i in range(r):
            y = (pow(y, 2, n) + c) % n

        k = 0
        while k < r and g==1:
            ys = y
            for i in range(min(m, r-k)):
                y = (pow(y, 2, n) + c) % n
                q = q * abs(x-y) % n
            g = gcd(q, n)
            k += m
        r *= 2
    if g == n:
        while True:
            ys = (pow(ys, 2, n) + c) % n
            g = gcd(abs(x - ys), n)
            if g > 1:
                break

    return g

def jamcoin(coin):
    """
    (1 - 1/n)^9
    """
    for base in range(2,11):
        x = int(coin, base)
        if is_probable_prime(x):
            return None
            
    #print(coin)
    divisors = []
    for base in range(2,11):
        x = int(coin, base)
        try:
            d = pollard_brent(x)
        except Exception:
            return None
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
    solve(32, 500)
