#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: c.py
# $Date: Sat Apr 09 22:29:17 2016 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import numpy as np
from plumbum.cmd import factor
import sys

rng = np.random.RandomState(42)

def rand_str(n):
    assert n >= 2, n
    return '1' + (''.join(map(str, rng.randint(2, size=n-2)))) + '1'

def work(n):
    ''':return: is_compound, representative'''
    items = factor(n).strip().split()
    if len(items) == 2:
        return False, None
    return True, items[1]


def solve(n, count):
    while count > 0:
        s = rand_str(n)
        nums = [int(s, b) for b in range(2, 11)]
        is_compound, representative = zip(*map(work, nums))
        if all(is_compound):
            print(' '.join([s] + list(map(str, representative))))
            sys.stdout.flush()
            count -= 1

print('Case #1:')
solve(16, 50)

# vim: foldmethod=marker
