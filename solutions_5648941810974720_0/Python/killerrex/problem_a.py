#!/usr/bin/env python3
# coding=utf-8

"""
    Solve Round 1B 2016 p.A

    Author: killerrex
"""

import sys


def filter_out(txt, name):
    # Remove it from the string
    for c in name:
        p = txt.index(c)
        txt = txt[:p] + txt[p + 1:]
    return txt


def rem_keys(group, txt):
    delta = []
    for key in group:
        while key in txt:
            # Add the found number
            name = group[key]
            delta.append(name)
            txt = filter_out(txt, name)
    return txt, delta


def decoder(txt):
    """
    Decode the string
    Args:
        txt:

    Returns:

    """
    assert(isinstance(txt, str))
    values = [
        "ZERO", "ONE", "TWO", "THREE", "FOUR",
        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    ]

    unique = {
        'Z': 'ZERO',
        'W': 'TWO',
        'U': 'FOUR',
        'X': 'SIX',
        'G': 'EIGHT'
    }

    # First remove the easy ones:
    # Remove the 0
    number = []

    txt, delta = rem_keys(unique, txt)
    number.extend(delta)

    # Second round
    second = {
        'H': 'THREE',
        'F': 'FIVE',
        'S': 'SEVEN'
    }

    txt, delta = rem_keys(second, txt)
    number.extend(delta)

    # Last ones
    last = {
        'O': 'ONE',
        'I': 'NINE'
    }

    txt, delta = rem_keys(last, txt)
    number.extend(delta)

    assert(txt == '')

    number = [values.index(name) for name in number]
    number.sort()

    return ''.join(str(n) for n in number)


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
        print("Case #{}: {}".format(k+1, decoder(txt)))


def start():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fd:
            solve(fd)
    else:
        solve(sys.stdin)

if __name__ == '__main__':
    start()
