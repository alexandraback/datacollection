# -*- coding: utf-8 -*-


T = int(raw_input())
for test_case in xrange(1, T + 1):
    A, B, K = map(int, raw_input().split())

    answer = len([a & b for a in xrange(A) for b in xrange(B) if a & b < K])
    print 'Case #{}: {}'.format(test_case, answer)
