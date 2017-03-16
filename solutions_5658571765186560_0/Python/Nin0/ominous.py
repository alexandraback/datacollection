#!/usr/bin/python3

import sys

def gabriel_can_win(x, r, c):
    if r > c:
        r, c = c, r
    # r <= c
    if (r * c) % x != 0:
        return False  # Areas don't add up!
    if 1 <= x <= 2:
        return True
    if x == 3:
        if (r, c) == (1, 3):
            return False
        return True
    if x == 4:
        if (r, c) in [(1, 4), (2, 2), (2, 4)]:
            return False
        return True
    raise NotImplementedError

t = int(sys.stdin.readline())

for case_num in range(1, t+1):
    x, r, c = map(int, sys.stdin.readline().split())
    print("Case #{0}: {1}".format(
        case_num,
        'GABRIEL' if gabriel_can_win(x, r, c) else 'RICHARD'))
