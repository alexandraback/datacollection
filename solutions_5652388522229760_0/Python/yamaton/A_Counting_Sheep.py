"""
Google Code Jam
2016 Qualification Round
A. Counting Sheep

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


def integerdigits(n):
    """Construct list of decimal digits from the integer n

    >>> integerdigits(235)
    {2, 3, 5}
    """
    return {int(i) for i in str(n)}


def solve(n):
    if n == 0:
        return 'INSOMNIA'

    val = 0
    s = set()
    while len(s) < 10:
        val += n
        s |= integerdigits(val)
    return val


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        n = int(input())
        result = solve(n)
        pp()
        pp('n =', n)
        pp('result =', result)
        print(result)


if __name__ == '__main__':
    main()
