"""
Google Code Jam
2016 Round 1B

Problem B.
    :author: yamaton
    :date: 2016-04-30
"""

import itertools as it
import functools
import operator
import collections
import math
import sys


def solve(xs):
    s1, s2 = xs
    ns1 = list(map(lambda ls: ''.join(ls), it.product(*(list('0123456789') if c == '?' else [c] for c in s1))))
    ns2 = list(map(lambda ls: ''.join(ls), it.product(*(list('0123456789') if c == '?' else c for [c] in s2))))

    _, n1, n2 = min((abs(int(n1) - int(n2)), n1, n2) for n1 in ns1 for n2 in ns2)
    return n1, n2


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        xs = input().strip().split()
        assert len(xs) == 2
        n1, n2 = solve(xs)
        pp()
        pp('input =', xs)
        pp('result =', n1, n2)
        print(n1, n2)




if __name__ == '__main__':
    main()
