#!/usr/bin/env python3
from itertools import islice, combinations, product, starmap
import sys


class Jamcoin:
    def __init__(self, value, proof):
        self.value = value
        self.proof = proof

    def __str__(self):
        return self.value + ' ' + ' '.join(map(str, self.proof))


def gen_jamcoins(bit_length):
    assert bit_length % 2 == 0

    # Alternating sum = 0 is such a killer divisibility rule.
    proof = range(3, 12)
    all_lower_bits = range(1, bit_length - 1, 2)
    all_upper_bits = range(2, bit_length - 1, 2)

    for n in range(bit_length // 2):
        lower_bits = map(set, combinations(all_lower_bits, n))
        upper_bits = map(set, combinations(all_upper_bits, n))
        bitsets = starmap(set.union, product(lower_bits, upper_bits))

        for bitset in bitsets:
            bits = (str(int(bit in bitset)) for bit in range(1, bit_length - 1))
            yield Jamcoin('1' + ''.join(bits) + '1', proof)


def verify_jamcoin(jamcoin):
    assert all(int(jamcoin.value, base) % (base + 1) == 0
               for base in range(2, 11))


if __name__ == '__main__':
    verify = 'verify' in sys.argv
    T = int(input())

    for t in range(1, T + 1):
        bit_length, count = map(int, input().split(' ', 1))
        print('Case #{}:'.format(t))

        for jamcoin in islice(gen_jamcoins(bit_length), count):
            if verify:
                verify_jamcoin(jamcoin)
            print(jamcoin)
