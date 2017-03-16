#!/usr/bin/env python

import itertools

def run_one(N, S):
    sums = {}
    for i in range(N + 1):
        for comb in itertools.combinations(S, i):
            s = sum(comb)
            if s in sums:
                return [comb, sums[s]]
            else:
                sums[s] = comb

    return None


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        line = [int(x) for x in lines.popleft().split()]
        N, S = line[0], line[1:]

        sets = run_one(N, S)

        if sets is None:
            output.append('Case #{0}: Impossible'.format(t + 1))
        else:
            output.append('Case #{0}:'.format(t + 1))
            for s in sets:
                output.append(' '.join(map(str, s)))

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
