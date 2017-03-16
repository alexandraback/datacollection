#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: p1.py
# $Date: Sun May 11 18:54:23 2014 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def solve(p, q):
    if p <= 0 or p > q or q <= 0:
        return -1
    g = gcd(p, q)
    p /= g
    q /= g
    ans = 0
    while p < q:
        if q % 2:
            return -1
        ans += 1
        q /= 2
    if ans > 40:
        return -1
    while q > 1:
        if q % 2:
            return -1
        q /= 2
    return ans


def main():
    nr_case = int(raw_input())
    for case in range(1, nr_case + 1):
        p, q = map(int, raw_input().split('/'))
        x = solve(p, q)
        if x == -1:
            x = 'impossible'
        print 'Case #{}: {}'.format(case, x)

main()
