#!/usr/bin/env python3
from collections import *

def main(*args):
    b, m = map(int, args)
    try:
        bridges = [[0 for _ in range(b)] for _ in range(b)]
        m -= 1
        for i in range(1, b):
            bridges[i - 1][i] = 1
        d = 2
        x = 2
        y = 0
        for i in range(m):
            bridges[y][x] = 1
            x += 1
            y += 1
            if x >= len(bridges):
                d += 1
                x = d
                y = 0
        return "POSSIBLE\n{}".format(
            '\n'.join(''.join(str(x) for x in b) for b in bridges))
    except IndexError:
        return "IMPOSSIBLE"

if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #{}: {}".format(i + 1, main(*input().split())))
