#!/usr/bin/env python3
# coding=utf-8

"""
    Solve Round 1A 2016 p.B

    Author: killerrex
"""

import sys


def as_number(fd, kind=int, single=False):
    """
    Read one line from the file and return it
    as the required kind numbers

    Args:
        fd: File descriptor
        kind: A transformation function like int, float...
        single: Return a single number

    Returns:
        The list/single values
    """

    txt = fd.readline().strip()
    values = [kind(s) for s in txt.split()]
    if single:
        if values:
            return values[0]
        else:
            return None
    else:
        return values


def solve(fd):
    """
    The missing values are the only ones an odd number of times

    Args:
        fd: File unit
    """
    # First line is the number of cases
    total = as_number(fd, single=True)

    for k in range(total):
        n = as_number(fd, single=True)

        count = {}
        for _ in range(2*n - 1):
            for h in as_number(fd):
                if h in count:
                    count[h] += 1
                else:
                    count[h] = 1

        # Now collect all the odd ones
        res = [h for h in count if count[h] % 2 != 0]
        res.sort()
        print("Case #{}: {}".format(k+1, ' '.join(str(r) for r in res)))


def start():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fd:
            solve(fd)
    else:
        solve(sys.stdin)

if __name__ == '__main__':
    start()
