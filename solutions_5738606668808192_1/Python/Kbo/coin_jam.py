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
            tmp = []
            for base in range(2, 10 + 1):
                jam_in_base = int(jam, base)
                divisor = find_divisor(jam_in_base)
                if not divisor:
                    break
                tmp.append(divisor)
            else:
                results[jam] = tmp
                if len(results) == j:
                    return results
    raise RuntimeError


def find_divisor(n):

    # try:
    #     sqrt_n = sqrt(n)
    # except OverflowError:
    #     sqrt_n = n // 2 + 1

    for i in range(2, 10):
        if n % i == 0:
            return i

    return False   # too long to find a divisor for this one


def main():
    results = process(500, 32)
    print("Case #1:")
    for result in results:
        print("{} {}".format(result, " ".join([str(i) for i in results[result]])))


if __name__ == "__main__":
    main()
