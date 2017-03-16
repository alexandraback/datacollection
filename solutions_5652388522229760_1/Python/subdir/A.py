#!/usr/bin/python

import sys


def solve(n):
    if n == 0:
        return None
    else:
        digits = set()
        for i in range(1, 1000):
            digits.update(list(str(i*n)))
            if len(digits) == 10:
                return i*n
        return None


def main():
    N = int(next(sys.stdin))
    for i in xrange(1, N+1):
        x = solve(int(next(sys.stdin)))
        print "Case #{}:".format(i), ('INSOMNIA' if x is None else x)


if __name__ == '__main__':
    main()

