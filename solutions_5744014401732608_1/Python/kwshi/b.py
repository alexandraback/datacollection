#!/usr/bin/python
from sys import stdin
from math import log

T = int(stdin.readline())

for i in range(1, T+1):
	B, M = [int(x) for x in stdin.readline().split()]
	if M > 1<<(B-2):
		print('Case #{}: IMPOSSIBLE'.format(i))
		continue
	print('Case #{}: POSSIBLE'.format(i))
	first = int(log(M, 2))
	slides = [[0 for _ in range(B)] for __ in range(B)]
	for j in range(first+1):
		for k in range(j+1, first+2):
			slides[j][k] = 1
	m = 0
	while m < M:
		add = int(log(M-m, 2))
		if add+1 != B-1: slides[add+1][B-1] = 1
		m += 1<<add
	for line in slides:
		print(''.join(str(x) for x in line))
