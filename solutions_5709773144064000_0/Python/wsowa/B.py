#!/usr/bin/env python

import sys


def solve(c, f, x):
    rate = 2
    time = 0.0
    win_time = x / rate
    i = 0
    while True:
        time += c / rate
        rate += f
        new_win_time = time + x / rate
        if new_win_time > win_time:
            return win_time
        else:
            win_time = new_win_time


def __main__():
    cases_no = int(sys.stdin.readline())
    for case_no in xrange(cases_no):
        [c, f, x] = map(float, sys.stdin.readline().split())

        print "Case #%d: %.7f" % (case_no + 1, solve(c, f, x))

__main__()
