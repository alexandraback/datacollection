#!/usr/bin/env python3

import math
import random


def cacl(k, c):
    ret = 0
    for cc in range(0, c):
        ret += k**cc
    return ret

def solve(T):
    line = input().split()
    K = int(line[0])
    C = int(line[1])
    S = int(line[2])
    assert(K == S)
    header = "Case #{0}:".format(T)
    base = cacl(K, C)
    for x in range(0, K):
        header += " {0}".format(base * x + 1);
    print(header)

def for_test():
    T  = int(input())
    for x in range(1, T + 1):
        solve(x)


if __name__ == '__main__':
    for_test()
