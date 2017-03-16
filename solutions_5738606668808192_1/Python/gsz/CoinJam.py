#!/usr/bin/env python3 

import itertools

def primes():
    def nats(start):
        while True:
            yield start
            start += 1

    def sieve(seq):
        first = next(seq)
        yield first
        yield from sieve(filter(lambda n: n % first != 0, seq)) 

    yield from sieve(nats(2))

some_primes = list(itertools.islice(primes(), 25))

def find_divisor(n):
    for p in some_primes:
        if n % p == 0:
            return p
    return None

def solve_case(N, J):
    numbin = '1' + '0'*(N-2) + '1'
    num = int(numbin, 2)
    jamcoins = []
    while len(numbin) == N and len(jamcoins) < J:
        divisors = []
        for radix in range(2, 10+1):
            div = find_divisor(int(numbin, radix))
            if div:
                divisors.append(div)
            else:
                break
        if len(divisors) == 9:
            jamcoins.append((numbin, divisors))
        num += 2
        numbin = bin(num)[2:]
    return jamcoins if len(jamcoins) == J else []

def main():
    T = int(input())
    for ci in range(1, T+1):
        N, J = [int(i) for i in input().split()]
        coins = solve_case(N, J)
        if not coins:
            print("Case #{}: FAIL".format(ci))
        else:
            print("Case #{}:".format(ci))
            for c, divs in coins:
                print("{} {}".format(c, ' '.join([str(d) for d in divs])))

main()
