#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: a.py
# $Date: Sat Apr 09 21:54:10 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>


m = int(input().strip())

for caseid in range(m):
    n = int(input().strip())
    if n == 0:
        ans = 'INSOMNIA'
    else:
        s = set()
        i = 1
        while len(s) != 10:
            c = n * i
            s |= set(str(c))
            i += 1
        ans = c
    print('Case #{}: {}'.format(caseid + 1, ans))



# vim: foldmethod=marker
