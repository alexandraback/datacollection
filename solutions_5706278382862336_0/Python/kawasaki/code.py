# -*- coding: utf-8 -*-

from fractions import gcd

T = int(raw_input())
for test_case in xrange(1, T + 1):
    P, Q = map(int, raw_input().split('/'))
    cd = gcd(P, Q)
    p, q = P / cd, Q / cd

    if bin(q).count('1') != 1:
        answer = 'impossible'
    else:
        a, b, depth = p, p, 0
        while True:
            depth += 1
            if 2 * b < q:
                a, b = 0, 2 * b
            else:
                break
        answer = depth
    print 'Case #{}: {}'.format(test_case, answer)
