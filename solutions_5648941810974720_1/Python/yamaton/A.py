"""
Google Code Jam
2016 Round 1B

Problem A.
    :author: yamaton
    :date: 2016-04-30
"""

import itertools as it
import functools
import operator
import collections
import math
import sys

NUMBERS = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


def subtract_and_accumulate(ch, num, counts, res):
    multiple = counts[ch]
    for c in NUMBERS[num]:
        counts[c] -= multiple
    return counts, res + [num] * multiple



def solve(s):
    counts = collections.Counter(s)
    res = []

    counts, res = subtract_and_accumulate('Z', 0, counts, res)
    counts, res = subtract_and_accumulate('W', 2, counts, res)
    counts, res = subtract_and_accumulate('U', 4, counts, res)
    counts, res = subtract_and_accumulate('X', 6, counts, res)
    counts, res = subtract_and_accumulate('G', 8, counts, res)

    counts, res = subtract_and_accumulate('O', 1, counts, res)
    counts, res = subtract_and_accumulate('R', 3, counts, res)
    counts, res = subtract_and_accumulate('F', 5, counts, res)
    counts, res = subtract_and_accumulate('S', 7, counts, res)

    counts, res = subtract_and_accumulate('I', 9, counts, res)

    assert(all(cnt == 0 for cnt in counts.values()))
    return ''.join(map(str, sorted(res)))


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        xs = input().strip()
        result = solve(xs)
        pp()
        pp('input =', xs)
        pp('result =', result)
        print(result)


if __name__ == '__main__':
    main()
