# -*- coding: utf-8 -*-

import copy


def solve(A, motes):
    ms = copy.copy(motes)
    ms.sort()
    while ms and ms[0] < A:
        A += ms.pop(0)
    if len(ms) <= 1:
        return len(ms)

    return min(
        1 + solve(A + A - 1, ms),
        1 + solve(A, ms[:-1]),
    )


T = int(raw_input())
for test_id in xrange(1, T + 1):
    A, N = map(int, raw_input().split())
    motes = map(int, raw_input().split())

    if A == 1:
        print 'Case #{}: {}'.format(test_id, N)
    else:
        print 'Case #{}: {}'.format(test_id, solve(A, motes))
