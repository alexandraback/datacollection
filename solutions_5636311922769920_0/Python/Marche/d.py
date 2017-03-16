#!/usr/bin/python3

import sys

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)

def locate(coord):
    return sum(coord[i]*K**(C-i-1) for i in range(len(coord)))

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        K, C, S = map(int, input().split())
        if S * C < K:
            result = "IMPOSSIBLE"
        else:
            tiles = [1+locate([(i+j) % K for j in range(C)]) for i in range(0, K, C)]
            result = ' '.join(map(str, tiles))

        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
