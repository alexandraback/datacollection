"""
Google Code Jam
2016 Qualification Round
D. Fractiles

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

def solve(k, c, s):
    assert k == s
    unit = k**(c-1)
    return [unit * i + 1 for i in range(k)]


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        k, c, s = map(int, input().strip().split())
        result = solve(k, c, s)
        pp()
        pp('(k, c, s) =', (k, c, s))
        pp('result =', result)

        if result is None:
            print('IMPOSSIBLE')
        else:
            print(*result)


if __name__ == '__main__':
    main()
