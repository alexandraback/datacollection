#!/usr/bin/env python3
#coding=gb18030

# CodeJam template 
# by scorpioLiu
# 2012.05.06

# Usage: CodeJam_X.py < X-small-practice.in > X-small-practice.out

import sys

# import other module
# import math

for tc in range(1, int(sys.stdin.readline()) + 1):

	# Begine
	res = 'No'
	s = {}
	
	n = int(sys.stdin.readline())
	
	for i in range(0, n):
		line = sys.stdin.readline().split()
		s[i+1] = []
		k = int(line[0])
		for j in range(1, k + 1):
			s[i + 1].append(int(line[j]))
	
	for i in s:
		A = set()
		flag = False
		A.add(i)
		q = []
		for j in s[i]:
			q.append(j)
		while len(q) != 0:
			x = q.pop(0)
			if x in A:
				res = 'Yes'
				flag = True
				break
			else:
				A.add(x)
			for j in s[x]:
				q.append(j)
		if flag:
			break
	# End
	
	print ('Case #%d: %s' % (tc, res))
	