#!/usr/bin/python3

import sys

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        N = int(input())
        heights = [0] * 2501
        for _ in range(2*N-1):
            for k in map(int, input().split()):
                heights[k] += 1
        tmp = sorted(k for k in range(2501) if heights[k] % 2 != 0)
        
        result = " ".join(str(k) for k in tmp)

        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
