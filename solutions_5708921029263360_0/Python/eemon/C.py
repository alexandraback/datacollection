#!/usr/bin/env python
# -*- coding: utf-8 -*-
from collections import Counter

def check(c):
    t1 = []
    t2 = []
    t3 = []

    for a in c:
        t1.append((a[0],a[1]))
        t2.append((a[1],a[2]))
        t3.append((a[0],a[2]))
    if Counter(t1).most_common()[0][1] > K:
        return False
    if Counter(t2).most_common()[0][1] > K:
        return False
    if Counter(t3).most_common()[0][1] > K:
        return False
    
    return True

T = int(input())

for case in range(T):
    J,P,S,K = map(int,input().split())
    comb = min(J*P*K, P*S*K)
    ans = []

    for i in range(1, J+1):
        for j in range(1, P+1):
            for s in range(1, S+1):
                if check(ans + [(i,j,s)]):
                    ans.append((i,j,s))

    print("Case #{0}: {1}".format(case+1, len(ans)))
    for a in ans:
        print(' '.join(map(str,a)))


