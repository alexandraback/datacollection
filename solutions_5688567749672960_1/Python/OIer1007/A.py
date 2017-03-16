#!/usr/bin/env python
# -*- coding: utf-8 -*-
#########################################################################
# File Name: A.py
# Author: wmg_1001
# mail: wmg_1007@163.com
# Created Time: Sun 03 May 2015 12:21:25 AM CST
#########################################################################

TT = int(raw_input())
t = 1000000
s = 1
f = [10000000] * (1000000 + 1)
f[1] = 1
last = [-1] * (1000000 + 1)
for i in range(s + 1, t + 1):
	if f[i - 1] + 1 < f[i]:
		f[i] = f[i - 1] + 1
		last[i] = i - 1
	S = str(i)
	S = S[ : : -1]
	ss = int(S)
	if ss <= i or ss > t:
		continue
	if f[ss] > f[i] + 1:
		f[ss] = f[i] + 1
		last[ss] = i

while TT > 0:
	TT -= 1
	t = int(raw_input())
	print f[t]