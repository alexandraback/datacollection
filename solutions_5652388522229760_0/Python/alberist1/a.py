#!/usr/bin/python3
# -*- coding: utf-8 -*-


def solve():
    n = int(input())
    if n == 0:
        return 'INSOMNIA'
    digits = set()
    for i in range(1, 1000000):
        digits |= set(str(i * n))
        if len(digits) == 10:
            return i * n
    raise NotImplementedError(n)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print('Case #%d:' % (i+1), solve())
