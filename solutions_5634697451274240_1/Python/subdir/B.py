#!/usr/bin/python

import sys
from itertools import groupby


def solve(stack):
    n = sum(1 for g, cs in groupby(stack))
    if stack[-1] == True:
        n -= 1
    return n


def main():
    N = int(next(sys.stdin))
    for i in xrange(1, N+1):
        stack = [True if c == '+' else False for c in next(sys.stdin).strip()]
        print "Case #{}: {}".format(i, solve(stack))


if __name__ == '__main__':
    main()

