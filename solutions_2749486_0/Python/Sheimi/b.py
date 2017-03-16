#!/usr/bin/env python
import math


def print_result(case_no, msg):
    print "Case #%d: %s" % (case_no, msg)


def run_case(case_no):
    x, y = raw_input().split(' ')
    xn, yn = int(x), int(y)
    x, y = 0, 0
    dx = True
    result = []
    if xn > x:
        for i in range(xn - x):
            result.append('W')
            result.append('E')
    if xn < x:
        for i in range(x - xn):
            result.append('E')
            result.append('W')
    
    if yn > y:
        for i in range(yn - y):
            result.append('S')
            result.append('N')
    if y > yn:
        for i in range(y - yn):
            result.append('N')
            result.append('S')
    result = "".join(result) 
    print_result(case_no, result)


if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
