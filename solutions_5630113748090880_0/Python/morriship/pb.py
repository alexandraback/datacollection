#!/usr/bin/pypy
# -*- coding: utf-8 -*-


def solve():
    n = int(raw_input())
    w = {}
    result = []
    for i in xrange(n + n - 1):
        nums = map(int, raw_input().split())
        for j in nums:
            w[j] = w.get(j, 0) + 1
    for key, val in w.iteritems():
        if val % 2:
            result.append(key)
    return ' '.join(map(str, sorted(result)))


if __name__ == '__main__':
    output = 'Case #{}: {}'

    t = int(raw_input())
    for i in xrange(1, t + 1):
        print output.format(i, solve())
