#!/usr/bin/python

import sys


def solve(k, c, start=0):
    '''
    >>> list(solve(1, 1))
    [0]
    >>> list(solve(1, 5))
    [0]
    >>> list(solve(3, 1))
    [0, 1, 2]
    >>> list(solve(3, 2))
    [1, 6]
    >>> list(solve(3, 3))
    [5]
    >>> list(solve(3, 4))
    [15]
    >>> list(solve(3, 5))
    [45]
    >>> list(solve(4, 2))
    [1, 11]
    >>> list(solve(4, 3))
    [6, 48]
    >>> list(solve(4, 4))
    [27]
    '''
    pos = 0
    res = 0
    while pos < k:
        cc = c
        while cc:
            if pos < k:
                res += pos
                pos += 1
            if cc == 1:
                yield res
                res = 0
                break
            else:
                res *= k
                cc -= 1


def main():
    T = int(next(sys.stdin))
    for i in xrange(1, T+1):
        K, C, S = map(int, next(sys.stdin).split())
        poslist = list(solve(K, C))
        if len(poslist) > S:
            print "Case #{}: IMPOSSIBLE".format(i)
        else:
            print "Case #{}: {}".format(i, " ".join(str(x + 1) for x in poslist))


if __name__ == '__main__':
    main()

