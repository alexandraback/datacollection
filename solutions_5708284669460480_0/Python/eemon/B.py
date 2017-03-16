#!/usr/bin/env python
# -*- coding: utf-8 -*-
import itertools

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

T = int(input())
for case in range(T):
    K,L,S = map(int,input().split())
    string_K = input()
    string_L = input()
    ans = 0
    count = 0
    max_banana = 0
    tmp = 0
    for t in itertools.product(*[string_K for i in range(S)]):
        tmp = occurrences(''.join(t),string_L)
        max_banana = max(max_banana,tmp)
        ans += tmp
        count += 1
    print("Case #{0}: {1}".format(case+1, max_banana - (ans / count)))


