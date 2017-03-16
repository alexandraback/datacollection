#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        N = int(sys.stdin.readline())
        S = set()
        for _ in range(2*N-1):
            for h in map(int, sys.stdin.readline().split()):
                if h in S:
                    S.remove(h)
                else:
                    S.add(h)
        print("Case #{}: {}".format(t+1, ' '.join(map(str,sorted(S)))))
