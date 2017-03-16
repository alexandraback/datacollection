#!/usr/bin/env python

import sys


def digits(n):
    digits = set()
    while n:
        digits.add(n % 10)
        n /= 10
    return digits


def solve(n):
    if not n:
        return "INSOMNIA"
    seen = set()
    i = 1
    while len(seen) != 10:
        seen.update(digits(n * i))
        i += 1
    return n * (i - 1)


def main():
    lines = sys.stdin.readlines()
    tests = int(lines[0])
    for i in xrange(tests):
        n = int(lines[i + 1])
        print "Case #%d: %s" % (i + 1, solve(n))


if __name__ == "__main__":
    main()
