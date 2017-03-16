#!/usr/bin/env python
# -*- coding: utf-8 -*-

# for small
T = int(input())
for case in range(T):
    K,C,S = map(int,input().split())
    if S < (K+1)//2:
        print("Case #{0}: {1}".format(case+1, "IMPOSSIBLE"))
    else:
        offset = sum([K**i for i in range(0,C)])
        ans = [min(offset * (2 * i) + 2, K**C) for i in range((K+1)//2)]
        print("Case #{0}: {1}".format(case+1, ' '.join(map(lambda x:str(int(x)), ans))))
