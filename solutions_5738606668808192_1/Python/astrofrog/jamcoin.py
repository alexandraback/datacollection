# Author: Thomas P. Robitaille
# Executed using Python 3

import random


def find_trivial_divisor(value):
    # We can concentrate on the subset of jamcoins that have low divisors -
    # otherwise we might get stuck on specific jamcoins that are large primes.
    for i in range(2, 10000):
        if value % i == 0:
            return i
    return None


def get_jamcoin_divisors(string):
    # Note: Returns None if string is not a jamcoin
    divisors = []
    for base in range(2, 11):
        value = int(string, base=base)
        divisor = find_trivial_divisor(value)
        if divisor is None:
            return None
        divisors.append(divisor)
    return divisors

with open('C-large.in', 'r') as f:
    t = int(f.readline())
    N, J = (int(x) for x in f.readline().split())

count = 0

print("Case #1:")

for value in range(0, 2**(N - 2)):

    string = format(value, '0{0:02d}b'.format(N - 2))
    string = '1' + string + '1'

    divisors = get_jamcoin_divisors(string)

    if divisors is None:
        continue

    print("{0} {1}".format(string, ' '.join(str(x) for x in divisors)))

    count += 1

    if count == J:
        break
