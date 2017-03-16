#!/usr/bin/env python3
# coding=utf-8

"""
Problem 2 for Google CodeJam 2014, Round 1B

Author: A. Ayala
killerrex@gmail.com
"""

import sys
from itertools import product


def naive(A, B, K):
    """
    Brute force solution, counting
    """
    t = 0
    for a,b in product(range(A), range(B)):
        if a & b < K:
            t += 1
    return t


def solution(A, B, K):
    """
    """
    return naive(A, B, K)


def solve(fd):
    """
    Solve all the cases from fd
    """

    t = int(fd.readline().strip())
    for k in range(t):
        A, B, K = [int(x) for x in fd.readline().strip().split()]
        res = solution(A, B, K)
        print("Case #{}: {}".format(k+1, res))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        infile = sys.stdin
    else:
        infile = open(sys.argv[1], 'r')

    solve(infile)

    infile.close()