#!/usr/bin/python3

import sys

args = sys.stdin.read().split()
T = int(args[0])
args = args[1:]
for ca in range(1, T + 1):
	n = int(args[0])
	m = int(args[1])
	args = args[2:]
	mat = []
	for i in range(n):
		mat.append([int(x) for x in args[:m]])
		args = args[m:]
	mr = [max(x) for x in mat]
	mc = [max(x) for x in zip(*mat)]
	print("Case #{}: ".format(ca), end='')
	for i in range(n):
		for j in range(m):
			if mat[i][j] < mr[i] and mat[i][j] < mc[j]:
				print("NO")
				break
		else:
			continue
		break
	else:
		print("YES")
