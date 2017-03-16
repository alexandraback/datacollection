#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
"""

# import sys
# sys.setrecursionlimit(10000)


def naive(A, B, K):
    cpt = 0
    for i in range(A):
        for j in range(B):
            if i&j < K:
                cpt += 1
    return cpt

def solve(A, B, K):
    return naive(A, B, K)

def main():
    T = int(raw_input())
    for i in range(1, T + 1):
        A, B, K = map(int, raw_input().split())
        res = solve(A, B, K)
        print "Case #{}: {}".format(i, res)

def test():
    pass

if __name__ == '__main__':
    # test()
    main()
