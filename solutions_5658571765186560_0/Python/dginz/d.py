#!/usr/bin/python3

import math

def canFill(x, r, c):
    if x >= 7:
        return False
    if (r * c) % x != 0:
        return False
    if r < x and c < x:
        return False
    s = (x - 1) // 2 + 1
    if r < s or c < s:
        return False
    if x == 4 and (r == 2 or c == 2):
        return False
    return True

T = int(input())
for case in range(T):
    (x, r, c) = map(int, input().split())
    print ("Case #%d: %s" % (case + 1, "GABRIEL" if canFill(x, r, c) else "RICHARD"))
