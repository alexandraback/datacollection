#!/usr/bin/python3
# -*- coding: utf-8 -*-


def solve():
    k, c, s = map(int, input().split())
    if k == 1:
        return 1
    res = []
    for i in range(0, k, c):
        ix = 0
        for j in range(c):
            if i + j < k:
                ix += k ** (c - j - 1) * (i+j)
        res.append(ix+1)
    if s < len(res):
        return "IMPOSSIBLE"
    return ' '.join(map(str, res))

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print('Case #%d:' % (i+1), solve())
