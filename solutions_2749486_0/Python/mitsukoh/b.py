#!/usr/bin/env python3
# coding: utf-8

def solve(gx, gy):
    x, y = 0, 0
    ret = ''

    while x != gx:
        dx = 1 if x < gx else -1
        ret += 'WE' if dx == 1 else 'EW'
        x += dx

    while y != gy:
        dy = 1 if y < gy else -1
        ret += 'SN' if dy == 1 else 'NS'
        y += dy

    return ret

for case in range(int(input())):
    a, b = list(map(int, input().split()))
    print('Case #{}: {}'.format(case + 1, solve(a, b)))
