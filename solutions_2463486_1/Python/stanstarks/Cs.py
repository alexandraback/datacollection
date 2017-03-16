#!/usr/bin/env python
import sys
import math

t_n = int(sys.stdin.readline())
		
l_list = []
for i in range(1,10**7):
	s = str(i)
	rs = s[::-1]
	if s == rs:
		l_n = i*i
		l = str(l_n)
		if l == l[::-1]:
			l_list.append(i*i)
for t_t in range(1, t_n+1):
	m = []
	[a, b] = map(int, sys.stdin.readline().split())
	ans = 0
	for i in range(len(l_list)):
		if l_list[i]>b:
			break
		elif l_list[i]>=a:
			ans += 1
	print("Case #%d: %d" % (t_t, ans))
