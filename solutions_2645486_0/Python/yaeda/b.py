#!/bin/python
# -*- coding: utf-8 -*-

import sys
import random
import math

def maximize(E, R, e, v_list):
    if len(v_list) == 1:
        return e * v_list[0]
    max_value = 0
    for spend in range(0, e + 1):
        remain_e = e - spend + R
        remain_e = remain_e if remain_e <= E else E
        value = spend * v_list[0] + maximize(E, R, remain_e, v_list[1:])
        if value > max_value:
            max_value = value
    return max_value

def solve(E, R, N, v_list):
    return maximize(E, R, E, v_list);

def solve_wrong(E, R, N, v_list):
    v_list.sort()
    v_list = v_list[::-1]
    e = R if E >= R else E
    return E * v_list[0] + e * sum(v_list[1:])
        
if __name__ == '__main__':
    lines = sys.stdin.readlines()
    T = int(lines[0][:-1])
    for i in range(0, T):
        E, R, N = [int(x) for x in lines[2 * i + 1][:-1].split(' ')]
        v_list = [int(x) for x in lines[2 * i + 2][:-1].split(' ')]
        result = solve(E, R, N, v_list)
        print 'Case #%d: %d' % ((i + 1), result)



