#!/usr/bin/python3
# -*- coding: utf-8 -*-
# †
from itertools import groupby

def f(s):
    grp = [k for k, _ in groupby(s)]
    if grp[-1] == '+':
        grp = grp[:-1]
    res = len(grp)
    return res

t = int(input())
for case in range(t):
    s = list(input())
    res = f(s)
    print('Case #{}: {}'.format(case+1, res))
