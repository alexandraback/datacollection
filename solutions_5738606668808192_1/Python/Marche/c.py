#!/usr/bin/python3

import sys
from itertools import product

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)


def smallerprime(n):
    from math import ceil, sqrt
    assert n > 1
    if n % 2 == 0:
        return 2
    else:
        for d in range(3, ceil(sqrt(n))+1, 2):
            if n % d == 0:
                return d
        return n

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        print("Case #{}:".format(case))
        print("Case #{}:".format(case), file=sys.stderr)

        N, J = map(int, input().split()) # 32, 500
        result = []

        for n in range(J):
            s = ('1' + '{:0{pad}b}'.format(n, pad = N // 2 - 2) + '1') * 2
            div = [1 + b ** (N // 2) for b in range(2, 11)]
            result.append((s, div))
            # assert all(int(s, b) % div[b-2] == 0 for b in range(2, 11))

        for s, div in result:
            print(s, ' '.join(map(str, div)))
            print(s, ' '.join(map(str, div)), file=sys.stderr)
