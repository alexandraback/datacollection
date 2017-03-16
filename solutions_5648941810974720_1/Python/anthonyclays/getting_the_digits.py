#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
from collections import Counter

def case(t):
    c = Counter(raw_input())

    chars = "EFGHINORSTUVWXZ"
    nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    mat = [[0] * 10 for _ in xrange(len(chars))]

    for (i, num) in enumerate(nums):
        for (k, v) in Counter(num).iteritems():
            mat[chars.index(k)][i] = v

    A = np.array(mat)
    
    y = np.array([c['E'], c['F'], c['G'], c['H'], c['I'], c['N'], c['O'], c['R'], c['S'], c['T'], c['U'], c['V'], c['W'], c['X'], c['Z'],])

    sol, _, _, _ = np.linalg.lstsq(A, y)
    sol = [int(round(n)) for n in sol]
    res = ""
    for (num, count) in zip(xrange(10), sol):
        res += str(num) * count
    print('Case #{}: {}'.format(t, res))

if __name__ == "__main__":
    map(case, xrange(1, int(raw_input())+1))
