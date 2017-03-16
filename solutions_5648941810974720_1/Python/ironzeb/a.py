#!/usr/bin/env python
# -*- Encoding: utf-8 -*-

from __future__ import print_function, unicode_literals

import sys
from collections import defaultdict

words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


def remove(m, word, count):
    for c in word:
        m[c] -= count
    return m


def solve(S):
    m = defaultdict(int)
    for c in S:
        m[c] += 1

    sixes = m["X"]
    m = remove(m, "SIX", sixes)

    zeroes = m["Z"]
    m = remove(m, "ZERO", zeroes)

    sevens = m["S"]
    m = remove(m, "SEVEN", sevens)

    eights = m["G"]
    m = remove(m, "EIGHT", eights)

    twos = m["W"]
    m = remove(m, "TWO", twos)

    fives = m["V"]
    m = remove(m, "FIVE", fives)

    fours = m["F"]
    m = remove(m, "FOUR", fours)

    ones = m["O"]
    m = remove(m, "ONE", ones)

    nines = m["N"] / 2
    m = remove(m, "NINE", nines)

    threes = m["T"]
    m = remove(m, "THREE", threes)

    # sanity check:
    for k, v in m.items():
        if v != 0:
            print("NO", k, v)

    ans = "0" * zeroes + "1" * ones + "2" * twos + "3" * threes + "4" * fours + "5" * fives \
        + "6" * sixes + "7" * sevens + "8" * eights + "9" * nines
    return ans

if __name__ == '__main__':
    f = sys.stdin
    T = int(f.readline())

    for t in range(T):
        S = f.readline().strip()
        ans = solve(S)
        print("Case #{}: {}".format(t + 1, ans))
