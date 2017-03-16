#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys


def NextState(state, mote):
    penalty, size = state
    result = [ (penalty + 1, size) ]
    if size > 1:
        while size <= mote:
            size += size - 1
            penalty += 1
        result.append( (penalty, size + mote) )
    return result


def Reduce(status):
    result = []
    previous_size = -1
    for penalty, size in sorted(status):
        if size <= previous_size:
            continue
        result.append((penalty, size))
        previous_size = size
    return result


def Solve(initial_size, motes):
    status = [ (0, initial_size) ]

    for mote in sorted(motes):
        next_status = []
        for state in status:
            next_status += NextState(state, mote)
        status = Reduce(next_status)
    return min(status)[0]


def main():
    number_of_cases = int(sys.stdin.readline())
    for case in xrange(1, number_of_cases + 1):
        initial_size, _ = map(int, sys.stdin.readline().split())
        motes = map(int, sys.stdin.readline().split())
        print "Case #{0}: {1}".format(case, Solve(initial_size, motes))


if __name__ == '__main__':
    main()
