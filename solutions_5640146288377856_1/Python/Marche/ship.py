#!/usr/bin/python3

import sys

DEBUG = False
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        R, C, W = map(int, input().split())
        result = R * (C // W) + (W-1 if C % W == 0 else W)


        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
