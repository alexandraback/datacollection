#!/usr/bin/env python

import math

def run_one(r, t):
    # Start with black ring 2*r+1
    # each ring increases area by 2, so next black ring is +4
    # solve for sum of increasing sizes

    s = 2*r - 1

    #return int((math.sqrt(s*s+8*t)-s)/4)

    # Alternate equation to reduce round-off error
    return int(2*t/(s+math.sqrt(s*s+8*t)))


def run(lines):
    output = []

    # Number of test cases
    N = int(lines.popleft())
    for n in range(N):
        r, t = [int(x) for x in lines.popleft().split()]
        result = run_one(r, t)

        output.append('Case #{0}: {1}'.format(n + 1, result))

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
