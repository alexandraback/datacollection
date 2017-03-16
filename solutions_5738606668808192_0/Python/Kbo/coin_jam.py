# -*- coding: utf-8 -*-

from math import sqrt
from utils import is_prime
from itertools import product


def process(j, n):

    results = {}
    for jam in product("01", repeat=n - 2):
        jam = "1" + "".join(jam) + "1"
        for base in range(2, 10 + 1):
            jam_in_base = int(jam, base)
            if is_prime(jam_in_base):
                break
        else:
            results[jam] = []
            for base in range(2, 10 + 1):
                jam_in_base = int(jam, base)
                results[jam].append(find_divisor(jam_in_base))

            if len(results) == j:
                return results
    raise RuntimeError


def find_divisor(n):

    sqrt_n = sqrt(n)
    for i in range(2, int(sqrt_n + 1)):
        if n % i == 0:
            return i
    raise RuntimeError(n)


def main():
    results = process(50, 16)
    print("Case #1:")
    for result in results:
        print("{} {}".format(result, " ".join([str(i) for i in results[result]])))


if __name__ == "__main__":
    main()
