#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: small.py
# $Date: Sat Apr 13 22:52:50 2013 +0800
# $Author: jiakai <jia.kai66@gmail.com>

import math

def test(i):
    if str(i) != str(i)[::-1]:
        return False
    s = int(math.sqrt(i))
    if s * s != i:
        return False
    return str(s) == str(s)[::-1]

def main():
    nr_case = int(raw_input())
    for casenu in range(1, nr_case + 1):
        A, B = map(int, raw_input().split())
        print 'Case #{}:'.format(casenu), \
                len(filter(test, range(A, B + 1)))

if __name__ == '__main__':
    main()
