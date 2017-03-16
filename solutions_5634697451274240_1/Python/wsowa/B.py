#!/usr/bin/env python

import string
import sys

trans = string.maketrans("+-", "-+")


def brute_force(pancakes):
    swaps = 0
    while True:
        # print(pancakes, len(pancakes), swaps)
        pancakes = pancakes.rstrip('+')
        if len(pancakes) == 0:
            return swaps
        if pancakes[0] == '+':
            i = pancakes.find('-')
            pancakes = pancakes[:i][::-1].translate(trans) + pancakes[i:]
            swaps += 1
        pancakes = pancakes.lstrip('-')[::-1].translate(trans)
        swaps += 1


def solve(pancakes):
    return brute_force(pancakes)


def get_digits(n):
    digits = set()
    while n > 0:
        digits.add(n % 10)
        n /= 10
    return digits


def __main__():
    cases_no = int(sys.stdin.readline())
    for case_no in xrange(cases_no):
        n = sys.stdin.readline().strip()
        print "Case #%d: %s" % (case_no + 1, solve(n))


__main__()