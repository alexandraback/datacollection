#!/usr/bin/env pypy3
# -*- coding: utf-8 -*-

# Modules from the Python standard library.
import collections
import functools
import itertools

# Modules from SymPy (licensed under BSD).
# This package can be downloaded from Python Package Index.
# URL: https://pypi.python.org/pypi/sympy
import sympy.ntheory.factor_


Jamcoin = collections.namedtuple("Jamcoin", "coin factors")
Validity = collections.namedtuple("Validity", "is_valid factors")
INVALID = Validity(False, [])


@functools.lru_cache()
def find_factors(n):
    return sympy.ntheory.factor_.pollard_pm1(n, 1000)


def validate_jamcoin(jamcoin):
    if not (jamcoin.startswith("1") and jamcoin.endswith("1")):
        return INVALID
    factors = []
    for base in range(2, 11):
        factor = find_factors(int(jamcoin, base))
        if factor is None:
            return INVALID
        factors.append(factor)
    return Validity(True, factors)


def produce_jamcoins(num_digits, total_num):
    coins = []
    num_produced = 0
    for i in range(2 ** (num_digits - 1) + 1, 2 ** num_digits, 2):
        cand = "{:b}".format(i)
        validity = validate_jamcoin(cand)
        if validity.is_valid:
            coins.append(Jamcoin(cand, validity.factors))
            num_produced += 1
        if num_produced >= total_num:
            break
    return coins


def main():
    t = int(input())
    for i in range(1, t + 1):
        n, j = map(int, input().split())
        print("Case #{}:".format(i))
        for coin in produce_jamcoins(n, j):
            print("{} {}".format(coin.coin, " ".join(map(str, coin.factors))))


if __name__ == '__main__':
    main()
