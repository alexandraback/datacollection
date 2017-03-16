#!/usr/bin/pypy
# -*- coding: utf-8 -*-


def solve():
    s = raw_input()
    ans = ''
    for ch in s:
        if not len(ans) or ch < ans[0]:
            ans += ch
        else:
            ans = ch + ans
    return ans


if __name__ == '__main__':
    output = 'Case #{}: {}'

    t = int(raw_input())
    for i in xrange(1, t + 1):
        print output.format(i, solve())
