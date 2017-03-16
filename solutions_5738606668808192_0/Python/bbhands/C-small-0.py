#!/usr/bin/python
# -*- coding: utf-8 -*-

from math import sqrt

def is_prime(x):
    prime = False
    if x > 1:
        prime = True
        k = 2
        n = sqrt(x) # to find square of x only once (or n = x ** 0.5 to get rid of math module)
        while k <= n and prime == True:
            if x % k == 0:
                prime = k
            k += 1
    return prime

T = int(raw_input().strip())
MAX = (10**16-1)/9

# prime = {}
# for k in xrange(2, MAX+1):
    # if k in prime:
        # continue

    # prime[k] = True
    # i = 2*k
    # while i <= MAX:
        # prime[i] = k
        # i += k

# def isPrime(S, b):
    # return prime[int(S, b)]

def next(S):
    # S: binary string
    s = int(S, 2)
    return bin(((s-1)/2 + 1)*2 + 1)[2:]

for t in xrange(0, T):
    N, J = tuple(map(int, raw_input().strip().split()))
    m = bin(2**15 + 1)[2:]
    answers = []
    while len(answers) < J:
        factors = []
        for b in xrange(2, 11):
            factor = is_prime(int(m, b))
            if factor is True:
                break
            factors.append(str(factor))

        if len(factors) == 9: # Got it
            answers.append(" ".join([m] + factors))

        m = next(m)

    print "Case #%i:" % (t+1)
    for ans in answers:
        print ans

