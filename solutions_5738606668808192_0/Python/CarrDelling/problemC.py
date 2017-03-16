#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Qualification round - Problem C - Coin Jam
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys
import random


def use_sieve(n):

    size = n//2
    sieve = [1]*size

    limit = int(n**0.5)
    for i in xrange(1, limit):
        if sieve[i]:
            val = 2*i+1
            tmp = ((size-1) - i)//val
            sieve[i+val::val] = [0]*tmp

    primes = [2] + [i*2+1 for i, v in enumerate(sieve) if v and i > 0]

    return primes


def test_prime(value, primes):

    for p in primes:
        if value % p == 0:
            return p

    return 0


def solve(n, j):

    primes = use_sieve(1000)

    min_r = (2 ** (n-1)) + 1
    max_r = (2 ** n) - 1

    chains = []

    while len(chains) < j:

        coin = random.randint(min_r, max_r)
        if coin % 2 == 0:
            coin += 1
        coin = "{0:b}".format(coin)

        divisors = []
        for base in xrange(2, 11):
            value = int(coin, base)
            divisor = test_prime(value, primes)

            if not divisor:
                break
            divisors.append(divisor)

        if len(divisors) > 8:
            elements = [coin] + [str(d) for d in divisors]
            chain = ' '.join(elements)
            chains.append(chain)

    output = '\n'+'\n'.join(chains)

    return output


input_path = sys.argv[1]

with open(input_path, 'r') as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        N, J = map(int, input_file.readline().strip().split())
        solution = solve(N, J)
        print 'Case #{0}:{1}'.format(case, solution)
