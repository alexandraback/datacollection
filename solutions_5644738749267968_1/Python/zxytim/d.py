#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: d.py
# $Date: Sun Apr 13 00:12:56 2014 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import sys

def solve_2(a, b):
    ret = 0
    n = len(a)
    b_start, b_end = 0, n - 1
    for i in range(n - 1, -1, -1):
        if a[i] > b[b_end]:
            ret += 1
            b_start += 1
        else:
            b_end -= 1
    return ret

def solve_1(a, b):
    n = len(a)
    ret = 0
    b_end = n - 1
    a_end = n - 1
    a_start = 0
    for i in range(n):
        if a[a_end] > b[b_end]:
            ret += 1
            a_end -= 1
            b_end -= 1
        else:
            a_start += 1
            b_end -= 1

    return ret

def solve(case_id, fin):
    n = int(fin.readline().rstrip())
    a = map(float, fin.readline().rstrip().split())
    b = map(float, fin.readline().rstrip().split())
    a.sort()
    b.sort()

    print 'Case #{}: {} {}'.format(case_id, solve_1(a, b), solve_2(a, b))


def main():
    fin = sys.stdin
    T = int(fin.readline().rstrip())
    for i in range(1, T + 1):
        solve(i, fin)

if __name__ == '__main__':
    main()
# vim: foldmethod=marker
