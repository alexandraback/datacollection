#!/usr/bin/python3

from collections import deque

T = int(input())

for t in range(T):
    X, Y = [int(i) for i in input().split()]
    dirs = ""
    if X > 0:
        dirs += "WE" * X
    elif X < 0:
        dirs += "EW" * -X
    if Y > 0:
        dirs += "SN" * Y
    elif Y < 0:
        dirs += "NS" * -Y
    print("Case #{}: {}".format(t + 1, dirs))
