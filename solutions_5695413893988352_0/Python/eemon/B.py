#!/usr/bin/env python
# -*- coding: utf-8 -*-

def check(c,j,cC,cJ):
    for i,cc in cC:
        if c[i] != cc:
            return False

    for i,cj in cJ:
        if j[i] != cj:
            return False

    return True


T = int(input())
for case in range(T):
    C,J = input().split()
    N = len(C)
    check_C = []
    check_J = []

    for i,c in enumerate(C):
        if c != '?':
            check_C.append((i,c))

    for i,j in enumerate(J):
        if j != '?':
            check_J.append((i,j))

    ans = False
    min_diff = 10**9
    f = "%0" + str(N) + "d"
    for i in range(10**N):
        for j in range(10**N):
            if check(f%i, f%j, check_C, check_J):
                if abs(i-j) < min_diff:
                    ans = (i,j)
                    min_diff = abs(i-j)

    print("Case #{0}: {1} {2}".format(case+1, f%ans[0], f%ans[1]))
