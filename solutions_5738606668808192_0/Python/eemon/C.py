#!/usr/bin/env python
# -*- coding: utf-8 -*-

def Nbase(N, x):
    L = len(list(str(x)))
    return sum([a* N ** (L - idx - 1) for idx, a in enumerate(map(int, list(str(x))))])

def check(digits):
    xs = []
    for i in range(2,11):
        ret = Nbase(i, digits)
        for k in range(2, int(ret**(1/2)) + 1):
            if ret % k == 0:
                xs.append(k)
                break
        else:
            return False
    return xs

T = int(input())
for case in range(T):
    N,J = map(int,input().split())
    ans = [0 for i in range(J)]
    count = 0

    for i in range(0, 2**(N-2)):
        x = i*2 + 1 + 2**(N-1)
        x = int(bin(x)[2:])
        for j in range(2,11):
            ret = Nbase(j, x)
            if ret % 2 != 0 and ret % 3 != 0 and ret % 5 != 0 and ret % 7 != 0 and ret % 13 != 0:
                break
        else:
            ans[count] = x
            count += 1
        if count >= J:
            break
    # print(ans)
    # print([check(a) for a in ans])
    print("Case #1:")
    for a in ans:
        if a != 0:
            print(a, ' '.join(map(str,check(a))))

