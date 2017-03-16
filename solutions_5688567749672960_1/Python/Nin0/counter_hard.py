#!/usr/bin/python3

import sys
from collections import deque

def flip(n):
    m = 0
    while n > 0:
        m *= 10
        m += n % 10
        n //= 10
    return m

def min_cnt(n):
    if n < 10:
        return n
    n_str = str(n)
    leading = int(n_str[0])
    l = len(n_str) // 2
    begin = n_str[:l]
    if begin == '1' + '0' * (l - 1):
        # Odštevamo do 99...9.
        goal = int('9' * (len(n_str) - 1))
        return min_cnt(goal) + (n - goal)
    goal = int(n_str[:-l] + '0' * (len(n_str) // 2 - 1) + '1')
    if n_str[-1] != '0':
        return min_cnt(flip(goal)) + 1 + (n - goal)
    else:
        return min_cnt(n-1) + 1

t = int(sys.stdin.readline())
for test_case_id in range(1, t+1):
    n = int(sys.stdin.readline())
    print('Case #{0}: {1}'.format(test_case_id, min_cnt(n)))
