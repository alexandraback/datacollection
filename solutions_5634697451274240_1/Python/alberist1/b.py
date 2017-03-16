#!/usr/bin/python3
# -*- coding: utf-8 -*-


def solve():
    s = input().strip()
    cnt = sum(x != y for x, y in zip(s, s[1:]))
    if s[-1] != '+':
        cnt += 1
    return cnt


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print('Case #%d:' % (i+1), solve())
