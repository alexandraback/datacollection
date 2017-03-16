#!/usr/bin/env python3

from math import sqrt

MIN_BASE = 2
MAX_BASE = 10
MAX_DIVISOR = 1000

CACHE = {}

def jamcoin(N, J, previous):
    # Strip the affix '1's from the previous coin.
    # Interpret the stripped coin base 2.
    # Start from the successor of the interpretation.
    value = (1 + int(previous[1: -1], 2)) if previous else 0

    # While we haven't found a good coin:
    while True:
        # Convert the value to binary.
        binary = bin(value)[2:]

        # Pad the interior of the coin with zeros if needed.
        missing = N - len(binary) - 2

        # Add '1' affices to create the coin.
        coin = '1' + missing * '0' + binary + '1'
        assert(N == len(coin))

        # Forget the divisors of the previous coin.
        divisors = []

        # For each base:
        for base in range(MIN_BASE, MAX_BASE + 1):
            # Interpret the coin in this base.
            interpretation = int(coin, base)

            # Linear search for a divisor, using a CACHE, up to MAX_DIVISOR
            if interpretation in CACHE:
                divisor = CACHE[interpretation]
            else:
                divisor = None
                for d in range(2, MAX_DIVISOR):
                    if interpretation % d == 0:
                        divisor = d
                        break
                CACHE[interpretation] = divisor

            # If we find one, remember it for this base.
            if divisor:
                divisors.append(d)
            # If we don't find one, move on to the next value.
            else:
                break

        # If we found all required divisors,
        # return the coin and its divisors.
        if len(divisors) == MAX_BASE - MIN_BASE + 1:
            return coin, divisors
        else:
            value += 1

    assert(False)

def oracle(coin, divisors):
    for i, divisor in enumerate(divisors):
        value = int(coin, i + MIN_BASE)
        assert(value % divisor == 0)

if __name__ == '__main__':

    T = int(input())
    for i in range(1, T+1):
        N, J = map(int, input().split())
        print('Case #{}:'.format(i))

        coin = None
        for j in range(J):
            coin, divisors = jamcoin(N, J, coin)
            oracle(coin, divisors)
            print('{} {}'.format(coin, ' '.join([str(d) for d in divisors])))
