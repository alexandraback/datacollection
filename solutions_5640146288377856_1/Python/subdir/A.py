#!/usr/bin/python
# coding: utf-8

from __future__ import print_function

import sys
from sys import stdin


def turns_per_row(C, W):
    '''
    >>> turns_per_row(5, 5)
    1
    >>> turns_per_row(6, 5)
    1
    >>> turns_per_row(9, 5)
    1
    >>> turns_per_row(10, 5)
    2
    >>> turns_per_row(11, 5)
    2
    >>> turns_per_row(14, 5)
    2
    >>> turns_per_row(15, 5)
    3
    '''
    return C // W


def solve(R, C, W):
    '''
    >>> solve(1, 4, 2)
    3
    >>> solve(1, 7, 7)
    7
    >>> solve(2, 5, 1)
    10

    >>> solve(6, 7, 1)
    42
    >>> solve(1, 5, 5)
    5
    >>> solve(1, 6, 5)
    6
    >>> solve(1, 7, 5)
    6
    >>> solve(1, 10, 5)
    6
    >>> solve(2, 10, 5)
    8
    '''
    turns = R * turns_per_row(C, W) + W
    if C % W == 0:
        turns -= 1
    return turns


def main():
    T = int(next(stdin))
    for t in range(1, T+1):
        R, C, W = map(int, next(stdin).split())
        print("Case #{}: {}".format(t, solve(R, C, W)))


if __name__ == '__main__':
    main()

