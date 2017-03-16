import os
from fractions import gcd
from functools import reduce
from itertools import product
from math import floor


def process(input_file, out):
    t = int(input_file.readline())

    for i in range(1, t + 1):
        results = solve(*map(int, input_file.readline().strip().split(' ')))
        out.write("Case #%i:\n" % i)
        for jamcoin, divisors in results:
            out.write("%s %s\n" % (jamcoin, " ".join(map(str, divisors))))


def isqrt(n):
    return floor(n **.5)


class Primes:

    def __init__(self, n):

        # a list of 10 million first primes, from the internet http://www.primos.mat.br/Ate100G_en.html
        primes_file_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "primes_list.txt")
        primes = []
        with open(primes_file_path, "r") as primes_file:
            for line in primes_file:
                primes += map(int, line.split())

                if primes[-1] > n:
                    break

        self._list = primes

    def find_divisor(self, number):
        root = isqrt(number)

        for p in self._list:
            if number % p == 0:
                return p
            elif p > root:
                return None
        return None


def solve(n, j):

    primes = Primes(10 ** (n // 2))

    limit = 2 ** n
    bases = list(range(2,11))

    for base2 in range(1 + 2 ** (n - 1), limit, 2):
        d = base2
        k = 0
        current = [0] * 9
        while d:
            d, m = divmod(d, 2)
            if m:
                for i, b in enumerate(bases):
                    current[i] += b ** k
            k += 1

        divisors = [0] * 9
        for i, number in enumerate(current):
            divisor = primes.find_divisor(number)
            if divisor:
                divisors[i] = divisor
            else:
                break
        else:
            # this is a jamcoin
            base10 = current[-1]
            yield (str(base10), divisors)

        # next step
        for i, base in enumerate(range(2, 11)):
            current[i] += base
    else:
        raise ValueError()
