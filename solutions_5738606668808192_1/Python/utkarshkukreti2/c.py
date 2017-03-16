from __future__ import print_function
from random import randrange
import sys

from sympy.ntheory import primefactors
from sympy.ntheory.primetest import isprime

def first_divisor(n):
    return primefactors(n, limit=10)[0]

def solve(N, J):
    found = 0
    i = 0
    while found < J:
        s = "1" + "{:030b}".format(i) + "1"
        any_prime = False
        for base in range(2, 11):
            n = int(s, base)
            any_prime = any_prime or isprime(n)
            if any_prime:
                break
        out = ""
        if not any_prime:
            try:
                out += s
                for base in range(2, 11):
                    n = int(s, base)
                    out += " " + str(first_divisor(n))
                print(out)
            except IndexError:
                i += 1
                continue
            found += 1
        i += 1

for t in xrange(1, 1 + int(raw_input())):
    n, j = map(int, raw_input().split())
    print("Case #{}:".format(t))
    solve(n, j)
