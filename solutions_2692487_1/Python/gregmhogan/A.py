#!/usr/bin/env python

import math

def run_one(A, N, motes):
    # greedy
    # always eat smallest mote
    # calculate number of motes to eat next mote
    # add if can add a mote to eat the smallest mote
    # else remove all motes

    if A == 1:
        return N

    if N == 0:
        return 0

    motes.sort()

    # Try to eat the smallest mote
    if A > motes[0]:
        return run_one(A + motes[0], N-1, motes[1:])
    else:
        # N is number of removal operations
        if_add_mote = 1 + run_one(2*A-1, N, motes)
        return min(if_add_mote, N)


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        A, N = [int(x) for x in lines.popleft().split()]
        motes = [int(x) for x in lines.popleft().split()]

        result = run_one(A, N, motes)

        output.append('Case #{0}: {1}'.format(t + 1, result))

    return output


# Google Code Jam submissions must run stand-alone.
# This code shall be copied into each solution.
if __name__ == '__main__':
    import os
    import sys
    from collections import deque

    infile = sys.argv[1]
    with open(infile) as file:
        lines = deque(file.readlines())
        output = run(lines)
        print os.linesep.join(output)
