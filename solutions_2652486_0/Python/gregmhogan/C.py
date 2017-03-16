#!/usr/bin/env python

import collections
import math

def prime_generator(n=None):
    """Compute prime numbers.  If the optional integer is given, only numbers
    less than or equal to the given integer are returned.

    >>> list(prime_generator(1))
    []
    >>> list(prime_generator(2))
    [2]
    >>> list(prime_generator(100))
    [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
    """

    if n and n < 2:
        return

    # Yield'ing '2' as a special case allows skipping
    # all even numbers below
    yield(2)

    odd_primes = []
    next_integer = 3

    while not n or next_integer <= n:
        is_prime = True

        for prime in odd_primes:
            # Factors must be less than the square root
            if next_integer < prime * prime:
                break

            # Composite if evenly divisible
            if next_integer % prime == 0:
                is_prime = False
                break

        if is_prime:
            # Yield and store the prime number
            yield(next_integer)
            odd_primes.append(next_integer)

        # Skip even numbers
        next_integer += 2


def factor_list(n):
    """Compute prime factors of an integer.

    >>> factor_list(29)
    [29]
    >>> factor_list(72)
    [2, 2, 2, 3, 3]
    >>> factor_list(13195)
    [5, 7, 13, 29]
    >>> factor_list(600851475143)
    [71, 839, 1471, 6857]
    """

    factors = []

    # Use a generator to provide all potential prime divisors
    primes = prime_generator(int(math.sqrt(n)))

    try:
        while n > 1:
            p = primes.next()
            while n % p == 0:
                factors.append(p)
                n /= p
    except StopIteration:
        # The leftover quotient is prime
        factors.append(n)

    return factors


def factor_map(n):
    """Compute prime factors of an integer.

    >>> factor_map(29)
    {29: 1}
    >>> factor_map(72)
    {2: 3, 3: 2}
    """
    map = collections.defaultdict(int)
    for factor in factor_list(n):
        map[factor] = map.get(factor, 0) + 1

    return map


def run_one(N, M, K, products):
    min3 = 0
    min4 = 0
    min5 = 0

    for p in products:
        f = factor_map(p)
        #print f
        min3 = max(min3, f[3])
        min4 = max(min4, int(f[2]/2))
        min5 = max(min5, f[5])

    #print min3, min4, min5

    two = N - min3 - min4 - min5

    return [2] * two + [3] * min3 + [4] * min4 + [5] * min5


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        R, N, M, K = [int(x) for x in lines.popleft().split()]
        output.append('Case #{0}:'.format(t + 1))

        for r in range(R):
            products = [int(x) for x in lines.popleft().split()]

            result = run_one(N, M, K, products)

            output.append(''.join([str(r) for r in result]))

    return output


# Google Code Jam submissions must run stand-alone.
# This code shall be copied into each solution.
if __name__ == '__main__':
    import os
    import sys
    from collections import deque

    infile = sys.argv[1]
    with open(infile) as file:
        lines = deque(file.readlines())
        output = run(lines)
        print os.linesep.join(output)
