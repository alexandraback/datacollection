"""
Google Code Jam
2016 Qualification Round
B. Revenge of the Pancakes

Problem
    :author: yamaton
    :date: 2016-04-08
"""

import itertools as it
import functools
import operator
import collections
import math
import sys

sys.setrecursionlimit(1000)

def reduced_count(tf, length):
    if length == 1:
        return 0 if tf else 1
    return 1 + reduced_count(not tf, length - 1)


# https://docs.python.org/3/library/itertools.html
def unique_justseen(iterable, key=None):
    "List unique elements, preserving order. Remember only the element just seen."
    # unique_justseen('AAAABBBCCDAABBB') --> A B C D A B
    # unique_justseen('ABBCcAD', str.lower) --> A B C A D
    return map(next, map(operator.itemgetter(1), it.groupby(iterable, key)))


def solve(s):
    tf = s[0] == '+'
    length = sum(1 for _ in unique_justseen(s))
    return reduced_count(tf, length)


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        s = input().strip()
        result = solve(s)
        pp()
        pp('s =', s)
        pp('result =', result)
        print(result)


if __name__ == '__main__':
    main()
