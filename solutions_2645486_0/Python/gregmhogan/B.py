#!/usr/bin/env python

import math

def run_one(E, R, N, values, energy):
    if N == 1:
        return energy * values[0]

    max_gain = 0

    # e is energy used for this activity
    for e in range(energy+1):
        gain = e * values[0] + run_one(E, R, N-1, values[1:], min(E, energy - e + R))
        max_gain = max(gain, max_gain)

    return max_gain


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        E, R, N = [int(x) for x in lines.popleft().split()]
        values = [int(x) for x in lines.popleft().split()]

        result = run_one(E, R, N, values, E)

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
