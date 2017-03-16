#!/usr/bin/env python

import sys
import random

_mrpt_num_trials = 5  # number of bases to test


def is_probable_prime(n):
    """
    Miller-Rabin primality test.

    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.

    >>> is_probable_prime(1)
    Traceback (most recent call last):
        ...
    AssertionError
    >>> is_probable_prime(2)
    True
    >>> is_probable_prime(3)
    True
    >>> is_probable_prime(4)
    False
    >>> is_probable_prime(5)
    True
    >>> is_probable_prime(123456789)
    False

    >>> primes_under_1000 = [i for i in range(2, 1000) if is_probable_prime(i)]
    >>> len(primes_under_1000)
    168
    >>> primes_under_1000[-10:]
    [937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

    >>> is_probable_prime(6438080068035544392301298549614926991513861075340134\
3291807343952413826484237063006136971539473913409092293733259038472039\
7133335969549256322620979036686633213903952966175107096769180017646161\
851573147596390153)
    True

    >>> is_probable_prime(7438080068035544392301298549614926991513861075340134\
3291807343952413826484237063006136971539473913409092293733259038472039\
7133335969549256322620979036686633213903952966175107096769180017646161\
851573147596390153)
    False
    """
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
    d = n - 1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert (2 ** s * d == n - 1)

    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2 ** i * d, n) == n - 1:
                return False
        return True  # n is definitely composite

    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False

    return True  # no base tested showed n as composite


def is_coinjam(i):
    for b in xrange(2, 11):
        in_base = int(bin(i)[2:], b)
        if is_probable_prime(in_base):
            return False
    return True


def get_divisor(x):
    if x % 2 == 0:
        return 2
    n = 3
    while x % n != 0:
        n += 2
        # if n > x/2: return None
    return n


def get_divisors(i):
    return [get_divisor(int(bin(i)[2:], b)) for b in range(2, 11)]


def brute_force(n, j):
    for i in xrange(2 ** (n - 1) + 1, 2 ** n, 2):
        if is_coinjam(i):
            print " ".join([bin(i)[2:]] + map(str, get_divisors(i)))
            j -= 1
            if j == 0:
                return


def solve(n, j):
    return brute_force(n, j)


def __main__():
    cases_no = int(sys.stdin.readline())
    for case_no in xrange(cases_no):
        [n, j] = map(int, sys.stdin.readline().split())
        print "Case #%d:" % (case_no + 1)
        solve(n, j)


__main__()
