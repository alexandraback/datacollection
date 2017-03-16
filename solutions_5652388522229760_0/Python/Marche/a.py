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
        if N == 0:
            result = 'INSOMNIA'
        else:
            acc = N
            seen = set(str(N))
            while seen != set('1234567890'):
                acc += N
                seen.update(set(str(acc)))
            result = acc

        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
