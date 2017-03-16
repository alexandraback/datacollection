#!/usr/bin/env python

import numpy as np
import random

def isprime(n):
    '''returns if the number is prime. Failure rate: 1/4**PROB '''
    PROB=5
    if n==2: return True
    if n==1 or n&1==0:return False
    s=0
    d=n-1
    while 1&d==0:
        s+=1
        d>>=1
    for i in range(PROB):
        a=random.randint(2,n-1)
        composit=True
        if pow(a,d,n)==1:
            composit=False
        if composit:
            for r in xrange(0,s):
                if pow(a,d*2**r,n)==n-1:
                    composit=False
                    break
        if composit: return False
    return True


def get_divisor(n):
    if n % 2 == 0:
        return 2
    for i in xrange(3, 1000000, 2):
        if n % i == 0:
            return i
    return 0


for i in xrange(input()):
    N, J = [int(k) for k in raw_input().split()]
    count = 0
    print "Case #{}:".format(i+1)
    for k in xrange(2**(N-1)+1, 2**N, 2):
        a = bin(k)[2:]
        n = [int(a, j) for j in range(2, 11)]
        if any(map(isprime, n)):
            continue
        divisors = map(get_divisor, n)
        if any(map(lambda n: n == 0, divisors)):
            continue
        print a, ' '.join(map(str, divisors))
        count += 1
        if count == J:
            break


