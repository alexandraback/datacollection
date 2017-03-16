#!/usr/bin/env python3

from math import log

IMPOSSIBLE = 'IMPOSSIBLE'

def tiles(K, C, S):
    if K <= S:
        return list(range(1, K + 1))

    all_digits = range(K)

    # Split the original tiles into evenly sized chunks.
    width = int(K / S)

    # If there's not enough information per chunk, give up.
    if width > C:
        return IMPOSSIBLE

    result = []

    # For each student:
    for i in range(S):
        # Have each student verify their allocated tiles from the
        # original pattern; one chunk per student.
        my_digits = all_digits[width * i: min(width * (i+1), K)]

        # Interpret my assigned original tiles as a base-K number,
        # which will tell me my actual tile.
        my_tile = from_base(my_digits, K)

        assert(my_tile < K**C)

        result.append(my_tile + 1)

    return result


def oracle(K, C, S, result):
    if result == IMPOSSIBLE:
        assert(K / S > C)
        return

    assert(len(result) <= S)

    # Simulate cleaning the tiles and constructing knowledge set.
    unknown = set(range(K))
    for tile in result:
        original_tiles = to_base(tile - 1, K, C)
        for i in original_tiles:
            if i in unknown:
                unknown.remove(i)

    assert(not unknown)

def to_base(n, base, width):
    if width is None:
        width = base
    result = []

    for _ in range(width):
        result.append(n % base)
        n = int(n / base)

    return result

def from_base(digits, base):
    offset = 1
    result = 0
    for d in digits:
        result += offset * d
        offset *= base

    return result

if __name__ == '__main__':

    T = int(input())
    for i in range(1, T+1):
        K, C, S = map(int, input().split(' '))
        result = tiles(K, C, S)
        oracle(K, C, S, result)

        items = map(str, result) if result != IMPOSSIBLE else [IMPOSSIBLE]

        print("Case #{}: {}".format(i, ' '.join(items)))
