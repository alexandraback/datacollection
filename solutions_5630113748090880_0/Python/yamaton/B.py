"""
Google Code Jam
2016 Round 1A

Problem B.
    :author: yamaton
    :date: 2016-04-15
"""

import itertools as it
import functools
import operator
import collections
import math
import sys


def solve(xss, n):
    cnt = collections.Counter(it.chain.from_iterable(xss))
    res = sorted(n for (n, c) in cnt.items() if c % 2 > 0)
    assert len(res) == n
    return res


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        n = int(input())
        xss = [[int(s) for s in input().strip().split()] for _ in range(2*n-1)]
        assert len(xss[0]) == n
        result = solve(xss, n)
        result = ' '.join(str(i) for i in result)
        pp()
        pp('xss =', xss)
        pp('result =', result)
        print(result)


if __name__ == '__main__':
    main()
