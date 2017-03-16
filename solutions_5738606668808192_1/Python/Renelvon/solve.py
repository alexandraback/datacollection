#!/usr/bin/env python3
import sys


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    primes = (2, 3, 5, 7)
    with open(input_file) as f_in:
        next(f_in)
        for i, input_line in enumerate(f_in):
            N, J = tuple(int(s) for s in input_line.split())
            jamcoins = solve_instance(N, J, primes)
            print("Case #%d:" % (i + 1))
            for coin in jamcoins:
                print(" ".join(str(s) for s in coin))


def solve_instance(N, J, primes):
    num = 2 ** (N - 1) + 1
    jamcoins = []

    while len(jamcoins) < J:
        num_s = bin(num)[2:]
        divisors = [num_s]
        for base in range(2, 11):
            d = divisor_of(int(num_s, base=base), primes)
            if d is None:
                break
            else:
                divisors.append(d)
        else:
            jamcoins.append(divisors)
        num += 2

    return jamcoins


def divisor_of(n, primes):
    for p in primes:
        if n % p == 0:
            return p
    return None


if __name__ == '__main__':
    main()
