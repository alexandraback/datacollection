#!/usr/bin/env python

def run_one(A, B):
    recycled = set()

    for m in range(A, B):
        ms = str(m)
        for i in range(len(ms)):
            n = ms[i:] + ms[:i]
            ni = int(n)
            if m < ni and ni <= B:
                recycled.add((m, ni))

    return len(recycled)


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        A, B = [int(x) for x in lines.popleft().split()]

        recycled = run_one(A, B)

        output.append('Case #{0}: {1}'.format(t + 1, recycled))

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
