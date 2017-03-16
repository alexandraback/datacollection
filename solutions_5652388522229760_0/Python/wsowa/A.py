#!/usr/bin/env python

import sys


def bruteForce(n):
    x = n
    digits = set()
    while True:
        digits.update(get_digits(x))
        if len(digits) == 10:
            return x
        x += n


def solve(n):
    if n == 0:
        return "INSOMNIA"
    else:
        return bruteForce(n)


def get_digits(n):
    digits = set()
    while n > 0:
        digits.add(n % 10)
        n /= 10
    return digits


def __main__():
    cases_no = int(sys.stdin.readline())
    for case_no in xrange(cases_no):
        n = int(sys.stdin.readline())
        print "Case #%d: %s" % (case_no + 1, solve(n))


__main__()
