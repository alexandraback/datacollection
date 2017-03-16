#!/usr/bin/env python
# -*- coding: utf-8 -*-

T = int(input())
for case in range(T):
    R,C,W = map(int,input().split())
    print("Case #{0}: {1}".format(case+1,C//W + W + (0 if C%W == 0 else 1) - 1))
