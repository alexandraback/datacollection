# -*- coding: utf-8 -*-
"""
Created on Sun May 11 16:15:32 2014

@author: poonna
"""

import numpy as np

def factor_of_two(n):
    power = 0
    while n%2 == 0:
        power = power + 1
        n = n // 2
    return (power, n)

def check(n, d):
    a, b = factor_of_two(d)
    if n%b == 0:
        c = int(np.log2(n/b))
        return a - c
    else:
        return None

num_tests = int(raw_input())
for i in range(num_tests):
    data = raw_input().split('/')
    result = check(int(data[0]), int(data[1]))
    if result:
        print 'Case #' + str(i+1) + ': ' + str(result)
    else:
        print 'Case #' + str(i+1) + ': impossible'
