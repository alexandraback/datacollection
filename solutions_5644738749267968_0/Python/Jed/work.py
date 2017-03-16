#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: work.py
# $Date: Sat Apr 12 23:41:10 2014 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def solve_nondeceitful(a, b):
    blo = 0
    bhi = 0
    score = 0
    for i in a:
        while bhi < len(b) and b[bhi] < i:
            bhi += 1
        if bhi < len(b):
            bhi += 1
            continue
        assert blo < bhi
        score += 1
        blo += 1
    return score

def solve_deceitful(a, b):
    blo = 0
    score = 0
    for i in a:
        if i > b[blo]:
            score += 1
            blo += 1
    return score

def read(t=int):
    return map(t, raw_input().split())

def main():
    nr_case, = read()

    for case in range(1, nr_case + 1):
        read()
        a = read(float)
        b = read(float)
        a.sort()
        b.sort()
        print 'Case #{}:'.format(case), \
            solve_deceitful(a, b), solve_nondeceitful(a, b)
main()
