#!/usr/bin/python2
# -*- coding: utf-8 -*-
# $File: a.py
# $Date: Sat Apr 27 09:40:32 2013 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import math

ncase = int(raw_input())

for case_id in range(ncase):
    print "Case #{0}: " . format(case_id + 1), 
    [R, t] = [int(i) for i in raw_input().split()]
    f = lambda x: 2*x*(x+1)+(-3+2*R)*x
    l, r = 0, 2*10**18
    while l + 1 < r:
        m = (l + r) / 2
        if f(m) <= t:
            l = m;
        else: r = m;
    print l

