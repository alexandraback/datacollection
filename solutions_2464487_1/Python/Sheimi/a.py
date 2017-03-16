#!/usr/bin/env python
import math


def print_result(case_no, msg):
    print "Case #%d: %s" % (case_no, msg)


def run_case(case_no):
    a, b = raw_input().split()
    r, t = int(a), int(b)
    a = 2
    b = 2 * r -1
    c = -t
    delta = b * b - 4 * a * c
    result = (-b + math.sqrt(delta)) / (2 * a)

    result = int(result)

    left = (2 * a * result + b) ** 2
    right = delta
    if (left > right):
        result = result - 1

    result = str(result)
    print_result(case_no, result)


if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
