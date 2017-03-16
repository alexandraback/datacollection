#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)


def calculate_primes(limit):
    """
    Calculates all primes <= limit.

    >>> calculate_primes(10)
    [2, 3, 5, 7]
    >>> calculate_primes(3)
    [2, 3]
    """
    limit += 1
    is_prime = [True]*limit
    is_prime[0] = False
    is_prime[1] = False
    primes = []
    for i in range(2, limit):
        if not is_prime[i]:
            continue
        primes.append(i)
        for j in range(2*i, limit, i):
            is_prime[j] = False
    return primes

def find_factor(number, primes):
    for p in primes:
        if p >= number:
            break

        if number % p == 0:
            return p
    return None

primes = calculate_primes(2**10)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N, J = map(int, fin.readline().split())

    print("Case #%d:" % (case))
    count = 0
    number = 2**(N-1) + 1
    while count < J:
        s = bin(number)[2:]
        success = True
        factors = []
        for base in range(2, 11):
            basenum = int(s, base)
            factor = find_factor(basenum, primes)
            if factor is None:
                success = False
                break
            else:
                factors.append(factor)
        if success:
            count += 1
            print(s, ' '.join(map(str, factors)))
        number += 2




