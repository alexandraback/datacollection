#!/usr/bin/env python3
# coding=utf-8

"""
    Solve Round 1A 2016 p.C

    Author: killerrex
"""

import sys
import itertools


def fakes(topics):

    # sort and group
    topics.sort()

    groups = {}
    for key, g in itertools.groupby(topics, key=lambda pair: pair[0]):
        groups[key] = [pair[1] for pair in g]

    original = 0
    while groups:
        # First any one that has only 1 element, consider it original
        # and repeated in all the other places
        exhausted = ['Canary']
        while exhausted:
            exhausted = []
            for key in groups:
                values = groups[key]
                if len(values) == 1:
                    exhausted.append(key)
            # Pop from the groups dict
            for key in exhausted:
                ori = groups[key][0]
                for sub in groups:
                    if len(groups[sub]) <= 1:
                        continue
                    try:
                        groups[sub].remove(ori)
                    except ValueError:
                        continue
                del groups[key]
                original += 1

        # Now remove the unique elements in each group
        exhausted = []
        for key in groups:
            dups = list(groups[key])
            for name in groups[key]:
                for sub in groups:
                    if sub == key:
                        continue
                    if name in groups[sub]:
                        break
                else:
                    # This is unique
                    dups.remove(name)
                    original += 1
            # Any missing element is dup ==> consider fakes
            if dups:
                groups[key] = dups
            else:
                exhausted.append(key)
        for key in exhausted:
            del groups[key]

        # Final round, consider 1st element arbitrarily original
        for key in groups:
            values = groups[key]
            if len(values) > 1:
                groups[key] = [values[0]]
                break

    return len(topics) - original


def solve(fd):
    """

    Args:
        fd: File unit
    """
    # First line is the number of cases
    total = int(fd.readline().strip())

    for k in range(total):
        n = int(fd.readline().strip())
        topics = []
        for _ in range(n):
            s = fd.readline().strip()
            topics.append(s.split())

        print("Case #{}: {}".format(k+1, fakes(topics)))


def start():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fd:
            solve(fd)
    else:
        solve(sys.stdin)

if __name__ == '__main__':
    start()
