# coding: cp932

import sys
import math


f   = file(sys.argv[1])
out = file(sys.argv[1][:-3] + '.out', 'w')

caseCnt = int(f.readline())

for case in range(1, caseCnt+1):
	name, n = f.readline().split()
	n = int(n)
	L = len(name)
	score = [0]*L

	seq = 0
	for i in range(L-1, -1, -1):
		if not name[i] in ('a', 'i', 'u', 'e', 'o'):
			seq += 1
		else:
			seq = 0
		score[i] = seq
	pre = 0
	ans = 0
	for i in range(L):
		if score[i] >= n:
			ans += (i+1-pre)*(L-(i+n-1))
			pre = i+1
	print>>out,  'Case #%d:'%case, ans
