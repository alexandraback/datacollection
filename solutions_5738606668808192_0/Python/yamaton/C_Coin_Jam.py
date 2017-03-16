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

def nontrivial_divisor(n):
    if n <= 2:
        return None
    elif n % 2 == 0:
        return 2
    max_p = int(math.sqrt(n))
    for p in range(3, max_p + 1, 2):
        if n % p == 0:
            return p
    return None


def jamicoin(s):
    """
    >>> jamicoin('101')
    []

    >>> jamicoin('1001')
    [3, 2, 5, 2, 7, 2, 3, 2, 7]

    >>> jamicoin('100011')
    [5, 13, 3, 31, 43, 3, 73, 7, 3]

    >>> jamicoin('111111')
    [3, 2, 3, 2, 7, 2, 3, 2, 3]

    >>> jamicoin('111001')
    [3, 2, 5, 2, 7, 2, 3, 2, 11]
    """
    if not all(i in {'0', '1'} for i in set(s)):
        return False
    if not (s[0] == s[-1] == '1'):
        return False

    out = []
    for i in range(2, 11):
        val = nontrivial_divisor(int(s, i))
        if val is None:
            return []
        out.append(val)
    return out


def solve(n, j):
    coins = []
    cnt = 0
    x = 0
    while cnt < j:
        s = bin(x)[2:]
        candidate = '1' + s.zfill(n-2) + '1'
        divisors = jamicoin(candidate)
        if divisors:
            coins.append((candidate, tuple(divisors)))
            cnt += 1
        x += 1
    return coins


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
