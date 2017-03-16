#!/usr/bin/env python

def run_one(S, p, points):
    already_in = 0
    needs_surprise = 0

    if p == 0:
        return len(points)
    elif p == 1:
        return len(points) - points.count(0)

    for score in points:
        if score >= 3 * p - 2:
            already_in += 1
        elif score >= 3 * p - 4:
            needs_surprise += 1

    return already_in + min(S, needs_surprise)


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        line = [int(x) for x in lines.popleft().split()]
        N, S, p, points = line[0], line[1], line[2], line[3:]

        max_googlers = run_one(S, p, points)

        output.append('Case #{0}: {1}'.format(t + 1, max_googlers))

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
