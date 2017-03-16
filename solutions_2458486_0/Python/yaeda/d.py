#!/bin/python
# -*- coding: utf-8 -*-

import sys
import math
import itertools

N = 0
memo = []
boxes = []

def can_open(state, keys, order):
    global N, memo
    global boxes
    # check memo
    if memo[state] == 1:
        return order
    if memo[state] == 0:
        return []
    # all opened
    if state == (1 << N) - 1:
        memo[state] = 1
        return order
    # open next
#    for i in set(range(0, N)) - set(order):
    for i in range(0, N):
        if i in order: continue
        key = boxes[i][0]
        added_keys = boxes[i][2:]
        if ((state >> i & 1) != 1) and (key in keys):
            next_state = state | 1 << i
            keys.remove(key)
            res = can_open(next_state, keys + added_keys, order + [i])
            keys.append(key)
            if len(res) != 0:
                memo[next_state] = 1
                return res
            else:
                memo[next_state] = 0
    memo[state] = 0
    return []

def check(keys, order):
    if len(order) != N:
        return False
    for i in order:
        key = boxes[i][0]
        added_keys = boxes[i][2:]
        if key not in keys:
            return False
        keys.remove(key)
        keys += added_keys
    return True

def solve(keys):
    global N, memo
    tmp_keys = keys[:]
    memo = [-1] * (1 << N)
    order = can_open(0, keys, [])
    if len(order) != 0:
        return ' '.join([str(x+1) for x in order])
    return 'IMPOSSIBLE'

if __name__ == '__main__':
    global boxes
    lines = sys.stdin.readlines()
    C = int(lines[0][:-1])
    pos = 1
    for i in range(0, C):
        K, N = [int(x) for x in lines[pos][:-1].split(' ')]
        keys = [int(x) for x in lines[pos + 1][:-1].split(' ')]
        boxes = []
        for j in range(0, N):
            boxes.append([int(x) for x in lines[pos + 2 + j][:-1].split(' ')])
        result = solve(keys)
        print 'Case #%d: %s' % (i + 1, result)
        pos += N + 2
