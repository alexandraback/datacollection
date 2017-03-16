#!/usr/bin/python3
# -*- coding: utf-8 -*-

import math


def solve():
    n, j = map(int, input().split())
    first = int('1' + '0' * (n - 2) + '1', 2)
    cnt = 0
    for i in range(0, 1000000000, 2):
        b = bin(first + i)[2:]
        r = []
        for s in range(2, 11):
            v = int(b, s)
            for x in range(2, 300):
                if v % x == 0:
                    r.append(x)
                    break
            else:
                break
        else:
            print(b, *r)
            cnt += 1
            if cnt == j:
                break
    assert j == cnt



if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print('Case #%d:' % (i+1))
        solve()
