#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        res = ""
        S = sys.stdin.readline()
        for c in S:
            if c + res >= res + c:
                res = c + res
            else:
                res = res + c
        sys.stdout.write("Case #{}: {}".format(t+1, res))
