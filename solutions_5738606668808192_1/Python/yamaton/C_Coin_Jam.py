"""
Google Code Jam
2016 Qualification Round
C. Coin Jam

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


def checker(outfilename, n):
    with open(outfilename, 'r') as f:
        content = f.readlines()[1:]
    xss = [line.strip().split() for line in content if line.strip()]
    for xs in xss:
        coin = xs[0]
        assert len(coin) == n and coin[0] == coin[-1] == '1'
        rest = [int(s) for s in xs[1:]]
        assert all(int(coin, i) % d == 0 for (i, d) in zip(range(2, 11), rest))


def solve(n, j):
    assert n % 2 == 0
    assert n >= 4
    n_half = n // 2
    out = []
    for x in range(j):
        base = '1' + bin(x)[2:].zfill(n_half - 2) + '1'
        s = base + base
        factors = tuple(int(base, i) for i in range(2, 11))
        out.append((s, factors))
    return out


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d:" % _tc, end='\n')
        n, j = map(int, input().strip().split())
        result = solve(n, j)
        pp()
        pp('(n, j) =', (n, j))
        for (coin, seq) in result:
            pp('  ', coin, seq)
            print(coin, *seq)


if __name__ == '__main__':
    main()
