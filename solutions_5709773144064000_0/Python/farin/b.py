#!/usr/bin/env python
# -*- coding: utf-8 -*-


def solve(c, f, x):
    rate = 2.0
    t = 0
    while True:
        win_time = x / rate
        farm_time = c / rate
        farm_win_time = farm_time + x / (rate + f)
        if win_time < farm_win_time:
            return "%.7f" % (t+win_time)
        t += farm_time
        rate +=  f


if __name__ == "__main__":
    testcases = input()
    for case_n in xrange(1, testcases+1):
        case_data = map(float, raw_input().split())
        print("Case #%i: %s" % (case_n, solve(*case_data)))
