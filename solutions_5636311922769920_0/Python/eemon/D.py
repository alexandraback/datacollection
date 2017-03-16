#!/usr/bin/env python
# -*- coding: utf-8 -*-

# for small
T = int(input())
for case in range(T):
    K,C,S = map(int,input().split())
    offset = sum([K**i for i in range(0,C)])
    ans = [offset * i + 1 for i in range(S)]
    print("Case #{0}: {1}".format(case+1, ' '.join(map(lambda x:str(int(x)), ans))))
