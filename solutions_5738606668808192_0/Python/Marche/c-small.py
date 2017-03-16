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

        N, J = map(int, input().split())
        result = []
        for core in range(2**(N-2)):
            s = '1' + '{:0{pad}b}'.format(core, pad=N-2) + '1'
            div = []
            for b in range(2, 11):
                n = int(s, b)
                d = smallerprime(n)
                if d == n:
                    break
                else:
                    div.append(str(d))
            else:
                result.append((s, div))
                debug(len(result), s, div)
                if len(result) >= J:
                    break

        for s, div in result:
            print(s, ' '.join(div))
            print(s, ' '.join(div), file=sys.stderr)
