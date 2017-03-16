#!/usr/bin/env python3

from math import log

def missing(lists):
    # Every number should appear in an even number of lists.
    # Numbers which are in an odd number of lists are the missing numbers.
    odd = set()
    for l in lists:
        for n in l:
            if n in odd:
                odd.remove(n)
            else:
                odd.add(n)

    # Construct the missing list from strictly ascending missing numbers.
    return sorted(list(odd))

def oracle(lists, result):
    # Strictly ascending, no duplicates.
    assert(sorted(result) == result)
    for a, b in zip(result[:-1], result[1:]):
        assert(a != b)

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        N = int(input())

        lists = []
        for j in range(2*N - 1):
            lists.append(map(int, input().split()))

        result = missing(lists)
        oracle(lists, result)

        print("Case #{}: {}".format(i, ' '.join(map(str, result))))
