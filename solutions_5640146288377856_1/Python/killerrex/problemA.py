#!/usr/bin/env python3
# coding=utf-8

"""
  Solution to Round1C.A

  Author: killerrex@gmail.com
"""

import sys


def as_number(fd, kind=int, single=False):
    """
    Read one line from the file and return it
    as the required kind numbers

    :param fd: File descriptor
    :param kind: A transformation function like int, float...
    :param single: Return a single number
    :return: The list/single values
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


def battelship(row, col, w):
    """
    Beat your brother!
    """
    # Step 1 field bombing to remove any w gap
    c, r = divmod(col, w)

    bombing = row*c

    # We have done an impact!
    # Now the best gap has w-1 spaces one one side and r on the other
    if r == 0:
        shank = w - 1
    else:
        # He can still cheat us once...
        shank = w
    return bombing + shank


def solve(fd):
    """
    Process an input and write the correct output...
    """

    cases = as_number(fd, single=True)

    for k in range(cases):
        r, c, w = as_number(fd)
        b = battelship(r, c, w)
        print("Case #{}: {}".format(k+1, b))


if __name__ == '__main__':

    # Read stdin and write stdout
    solve(sys.stdin)
