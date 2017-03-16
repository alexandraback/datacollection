#!/usr/bin/env python

def run_one(A, B):
    recycled = set()

    lenA = len(str(A))
    power = 10 ** (lenA - 1)
    myRange = range(lenA-1)

    for m in range(A, B):
        #print "m: " + str(m)
        n = m
        for i in myRange:
            n = power * (n % 10) + n / 10
            #print "n: " + str(n)
            if m < n and n <= B:
                recycled.add((m, n))

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
