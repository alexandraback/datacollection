#!/usr/bin/python3
# -*- coding: utf-8 -*-
# †
t = int(input())

for case in range(t):
    k, c, s = map(int, input().split())
    assert k == s
    res = ' '.join(map(str, range(1, k+1)))
    print('Case #{}: {}'.format(case+1, res))
