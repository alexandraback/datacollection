#!/usr/bin/env python3
# coding=utf-8

"""
    Solve Round 1A 2016 p.A

    Author: killerrex
"""

import sys


def winner(txt):
    """
    Reorder to obtain the last...
    """
    sol = txt[0]
    for c in txt[1:]:
        if c >= sol[0]:
            sol = c + sol
        else:
            sol += c
    return sol


def solve(fd):
    """
    Solve for the values from a file

    Args:
        fd: File unit
    """
    # First line is the number of cases
    total = int(fd.readline().strip())

    for k in range(total):
        txt = fd.readline().strip()
        print("Case #{}: {}".format(k+1, winner(txt)))


def start():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fd:
            solve(fd)
    else:
        solve(sys.stdin)

if __name__ == '__main__':
    start()
