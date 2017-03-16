#!/usr/bin/env python


DEBUG = False

import sys

def debug(*args):
    if DEBUG:
        print ' '.join(map(str, args))

def int_input():
    text = raw_input()
    return int(text)

def float_input():
    text = raw_input()
    return int(text)

def list_input(size=None):
    text = raw_input()
    str_values = text.split(' ')
    if size is not None:
        assert len(str_values) == size
    return str_values

def intlist_input(size=None):
    return map(int, list_input(size))

def floatlist_input(size=None):
    return map(float, list_input(size))

def loop(count, func):
    for x in xrange(0, count):
        func(x)

def print_case(idx, fmt, *args):
    prefix = 'Case #{}:'.format(idx + 1)
    if len(args):
        print prefix, fmt % args
    else:
        print prefix, fmt

class Plain(object):
    def __init__(self, size, init=None):
        self.size = size
        self.data = [init] * (self.size[0] * self.size[1])

    def __getitem__(self, coord):
        r, c = coord
        index = r * self.size[1] + c
        return self.data[index]

    def __setitem__(self, coord, item):
        r, c = coord
        index = r * self.size[1] + c
        self.data[index] = item

    def debug(self):
        debug('Plain {}x{}'.format(self.size[0], self.size[1]))
        for r in xrange(0, self.size[0]):
            row = [self[r, c] for c in xrange(0, self.size[1])]
            debug(row)


class PrimeDatabase(object):

    def __init__(self, n):
        self.primes = self.rwh_primes2(n + 1)

    @staticmethod
    def rwh_primes2(n):
        """ Input n>=6, Returns a list of primes, 2 <= p < n """
        # flake8: noqa
        # http://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
        correction = (n%6>1)
        n = {0:n,1:n-1,2:n+4,3:n+3,4:n+2,5:n+1}[n%6]
        sieve = [True] * (n/3)
        sieve[0] = False
        for i in xrange(int(n**0.5)/3+1):
            if sieve[i]:
                k=3*i+1|1
                sieve[      ((k*k)/3)      ::2*k]=[False]*((n/6-(k*k)/6-1)/k+1)
                sieve[(k*k+4*k-2*k*(i&1))/3::2*k]=[False]*((n/6-(k*k+4*k-2*k*(i&1))/6-1)/k+1)
        return [2,3] + [3*i+1|1 for i in xrange(1,n/3-correction) if sieve[i]]


class JamCoin(list):

    @classmethod
    def from_str(cls, s):
        self = cls()
        for c in s[::-1]:
            n = int(c)
            assert n in [1, 0]
            self.append(n)
        return self

    @classmethod
    def generate(cls, digit):
        import random
        self = cls()
        self.append(1)
        for _ in range(1, digit - 1):
            self.append(random.choice([1, 0]))
        self.append(1)
        assert len(self) == digit
        return self

    def validate(self):
        divisors = []
        for v in self.as_bases():
            for prime in pdb.primes:
                if prime >= v:
                    return None
                if v % prime == 0:
                    divisors.append(prime)
                    break
            else:
                return None
        assert len(divisors) == 9
        return divisors

    def __str__(self):
        return ''.join(map(str, self[::-1]))

    def __repr__(self):
        return self.__str__()

    def as_base(self, base):
        n = 0
        for i, c in enumerate(self):
            if c:
                n += base ** i
        return n

    def as_bases(self):
        return [self.as_base(base) for base in range(2, 11)]


pdb = PrimeDatabase(10000)


def random_search(digit, pool):
    while True:
        coin = JamCoin.generate(digit)
        s = str(coin)
        if s in pool:
            continue
        pool.add(s)
        divisors = coin.validate()
        if divisors:
            return coin, divisors


def linear_search(digit, count):
    indigit = digit - 2
    solutions = []
    for i in range(0, 2**indigit):
        i_bin = bin(i)[2:]
        padded = ('0' * indigit) + i_bin
        str_coin = '1' + padded[-indigit:] + '1'
        assert len(str_coin) == digit
        coin = JamCoin.from_str(str_coin)
        divisors = coin.validate()
        if divisors:
            solutions.append((coin, divisors))
        if len(solutions) >= count:
            break
    return solutions


def solution(idx):
    N, J = map(int, list_input())
    print_case(idx, '')
    answers = linear_search(N, J)
    assert len(answers) == J
    for coin, divisors in answers:
        print coin, ' '.join(map(str, divisors))


if __name__ == '__main__':
    count = int_input()
    loop(count, solution)
