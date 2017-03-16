#!/usr/bin/python
from __future__ import division,print_function
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org
import itertools
import operator
import string

sys.setrecursionlimit(5000)

T = int(sys.stdin.readline())
N,J = map(int,sys.stdin.readline().strip().split())

# this is enough even for the large dataset, because we need primes until sqrt(2**N)
primes = sympy.primerange(1, 2**17)
primelist = list(primes)
primeset = set(primelist)

def first_divisor(number,primes):
    for prime in primes:
        if number % prime == 0: return prime
    return number

def parse(s,base):
    result = 0
    for idx in range(len(s)):
        result += (int(s[-idx-1]))*(base**idx)
    return result

def parse_all(number):
    result = []
    s = "{0:b}".format(number)
    for b in range(2,11):
        result.append(parse(s,b))
    return result

def solve(N,J,primelist,primeset):
    i = 2**(N-1)-1
    solutions = []
    cnt = 0
    while i<2**(N):
        i+=2
        if i in primeset: continue
        numbers = parse_all(i)

        accepted = True

        divisors = ""

        for number in numbers:
            divisor = first_divisor(number,primelist)
            if divisor == number:
                accepted = False
                break
            divisors = divisors+" %s" % divisor

        if not accepted: continue

        solution = "{0:b} ".format(i)+divisors
        solutions.append(solution)
        if len(solutions)>=J: break
    return solutions

for t in range(1,T+1):
    print("Case #%i:" % (t,))
    solutions = solve(N,J,primelist,primeset)
    for solution in solutions:
        print(solution)

