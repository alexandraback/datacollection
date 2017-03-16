#!/usr/bin/env python3
# coding=utf-8

"""
Problem 1 for Google CodeJam 2014, Round 1C

Author: A. Ayala
killerrex@gmail.com
"""

import sys
import fractions


def ancestors_elf(q):
    """
    Find the number D=2^n such that q*D=2^40
    return p*D
    """
    # Calculate the factors of q
    r = 0
    for k in range(40):
        if r != 0:
            # Not possible
            return None
        if q == 1:
            return 40 - k
        q, r = divmod(q, 2)


def search_closest(p, n):
    """
    See how many generations admit p
    """
    # Keep the number of bits
    bits = p.bit_length() -1 + n
    return 40 - bits


def solution(p, q):
    """
    Solve for the lst of strings
    """
    n = ancestors_elf(q)
    if n is None:
        return "impossible"
    else:
        return search_closest(p, n)


def solve(fd):
    """
    Solve all the cases from fd
    """

    t = int(fd.readline().strip())
    for k in range(t):
        # Read P/Q
        f = fractions.Fraction(fd.readline().strip())
        res = solution(f.numerator, f.denominator)
        print("Case #{}: {}".format(k+1, res))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        infile = sys.stdin
    else:
        infile = open(sys.argv[1], 'r')

    solve(infile)

    infile.close()