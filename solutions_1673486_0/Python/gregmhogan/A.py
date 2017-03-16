#!/usr/bin/env python

def run_one(A, B, probabilities):
    # hit enter and start over
    best = 2 + B

    p = 1
    # use this many characters
    for a in range(1, A + 1):
        back = A - a
        p *= probabilities[a-1]

        ev = back + (1 + B - a) + (1 - p) * (1 + B)

        # correct
        #ev += p * (1 + B - a)

        # incorrect
        #ev += (1-p) * ((1 + B - a) + (1 + B))

        if ev < best:
            best = ev

    # finish => (1 + B - A) *
    # restart => 2 + B

    return best


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        A, B = [int(x) for x in lines.popleft().split()]
        probabilities = [float(x) for x in lines.popleft().split()]

        best = run_one(A, B, probabilities)

        output.append('Case #{0}: {1}'.format(t + 1, best))

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
