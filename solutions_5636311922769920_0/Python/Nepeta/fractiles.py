"""
https://code.google.com/codejam/contest/6254486/dashboard#s=p3
"""

import fileinput
import functools
import math


def spire(x, size, depth):
    s = set()
    for _ in range(depth):
        s.add(x % size)
        x //= size
    return s


def ncr(n, r):
    return functools.reduce(lambda x, y: x * y[0] // y[1], zip(range(n - r + 1, n+1), range(1, r+1)), 1)


def generate(x, size, depth, remaining_factors=None):
    if remaining_factors is None:
        remaining_factors = list(range(0, size))

    if depth == 0:
        yield x
    else:
        for factor in remaining_factors:
            for ret in generate(x * size + factor, size, depth - 1, [x for x in remaining_factors if x != factor]):
                yield ret


def main():
    lines = fileinput.input()

    cases = int(next(lines))

    for case in range(1, cases + 1):
        size, depth, slaves = map(int, next(lines).strip().split())

        # Only need ceil(size / depth) slaves?
        if slaves < math.ceil(size / depth):
            ans = 'IMPOSSIBLE'
        else:
            tiles = list()
            factors_remaining = list(range(size))
            while factors_remaining:
                factors = factors_remaining[:depth]
                factors_remaining = factors_remaining[depth:]
                index = 0
                for factor in factors:
                    index = index * size + factor
                tiles.append(index + 1)
            ans = ' '.join(str(tile) for tile in tiles)

        print("Case #{case}: {ans}".format(**locals()))

        """
        for i in range(size**depth):
            print(i, spire(i, size, depth))

        for x in generate(0, size, depth):
            print('Factor: ', x)
        """

if __name__ == '__main__':
    main()

