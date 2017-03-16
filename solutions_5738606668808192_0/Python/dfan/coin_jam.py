#!/usr/bin/python

import sys
from math import sqrt
from random import randint
from struct import unpack

# load the first 1000000 primes to be available globally
with open("primes","rb") as pdata:
    primes = list(unpack("i"*1000000, pdata.read()))
    primeSet = set(primes)

def solve(N, J, i):
    """Main solution"""
    # n start as the smallest N digit binary number starting and ending with 1
    # e.g. for N = 5, n in xrange(10001,11111 + 1)
    coins = ""
    for n in xrange(2**(N-1) + 1, 2**N, 2):
        divisors = []
        # convert to binary string
        binary_representation = "{0:b}".format(n)
        # iterate over bases, 2 to 10 inclusive
        for b in xrange(2, 10 + 1):
            interpretation = int(binary_representation, b)
            # Ignore this n if one of these is prime
            if is_prime(interpretation):
                break
            divisors.append(str(get_divisor(interpretation)))
        # At this point the ith entry in `divisors` should be a prime divisor
        # of `binary_representation` in base (i+2)
        if len(divisors) == 9:
            coins += "\n" + binary_representation + " " + " ".join(divisors)
            J -= 1
        if J <= 0:
            return "".join(coins)

def get_divisor(n):
    """
    Max value of N is 10^32, need to potentially check up to 10^16
    If we go past 1 000 000th prime (~15 000 000), fall back to incrementing
    divisor by 1 (slow)
    """
    for prime in primes:
        if n % prime == 0:
            return prime
    for candidate in xrange(primes[-1], int(sqrt(n))):
        if n % candidate == 0:
            return candidate

def is_prime(n):
    """Miller-Rabin primality testing"""
    # primes contains all primes up to 15485863. Use this first
    if n in primeSet:
        return True
    if n <= primes[-1]:
        return False

    # Miller-Rabin
    min_confidence = 10**12
    confidence = 1
    while confidence < min_confidence:
        a = randint(2,n-1)
        s = 0
        d = n-1
        while d % 2 == 0:
            s += 1
            d /= 2
        if pow(a,d,n) != 1 and all(pow(a, 2**r * d, n) != n-1 for r in xrange(0,s)):
            return False
        confidence *= 4
    return True

def read_int_list(line, separator=" "):
    return map(int, line.strip().split(separator))

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "input.txt" if no command line
filename = "C-large.in"
if len(sys.argv) >= 2:
    filename = sys.argv[1]
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        # pancake stack
        N, J = read_int_list(input_file.readline())
        result = solve(N, J, i)
        output_case(i, result)