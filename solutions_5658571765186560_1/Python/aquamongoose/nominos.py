#!/usr/bin/env python3

T = int(input())

for test in range(T):
    X, R, C = map(int, input().split())
    ans = 'GABRIEL'
    if R > C:
        R, C = C, R
    if (R*C)%X != 0 or X >= 7 or (X + 1) // 2 > R or X // 2 + 1 > C or (R, X) == (2, 4) or (R, X) == (3, 6):
        ans = 'RICHARD'
    print('Case #{}: {}'.format(test+1, ans))
