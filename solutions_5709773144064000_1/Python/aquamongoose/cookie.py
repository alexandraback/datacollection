#!/usr/bin/env python3
T = int(input())

def time(C, F, X):
    rate = 2
    cur = 0
    ans = 1e50
    for i in range(int(X+2)):
        ans = min(ans, cur + X/rate)
        cur += C/rate
        rate += F
    return ans

for case in range(1, T+1):
    print('Case #{}: '.format(case), end='')
    C, F, X = map(float, input().split())
    print(time(C, F, X))
