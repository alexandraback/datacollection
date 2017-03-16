#!/usr/bin/env python3

import sys
from collections import *

def print_sol(tc, n, line):
    POS = 'POSSIBLE'
    if line is None:
        POS = 'IMPOSSIBLE'

    print('Case #{}: {}'.format(tc, POS))
    if line is not None:
        print(line)
        for row in range(1, n):
            print('0' * (row + 1), end='')
            print('1' * (n - row - 1))

T = int(input())
for tc in range(1, T+1):
    B, M = [int(x) for x in input().split(' ')]

    if B == 2:
        if M == 1:
            print_sol(tc, B, '01')
        else:
            print_sol(tc, B, None)
        continue

    can_do = 2 ** (B-2)
    if M > can_do:
        print_sol(tc, B, None)
        continue

    line = '0'
    remain = M
    for x in range(B-3, -2, -1):
        val = 2 ** (max(0, x))
        if val <= remain:
            remain -= val
            line += '1'
        else:
            line += '0'

    assert remain == 0

    print_sol(tc, B, line)
