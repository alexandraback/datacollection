# -*- coding: utf-8 -*-

import sys


def solve():
    A, B, K = map(int, input().split())
    k_set = set([i for i in range(K)])

    return sum(1 for i in range(A) for j in range(B) if i & j in k_set)

def main():
    T = int(input())
    for i in range(1, T + 1):
        print('Case #{}: {}'.format(i, solve()))

if __name__ == '__main__':
    sys.exit(main())
