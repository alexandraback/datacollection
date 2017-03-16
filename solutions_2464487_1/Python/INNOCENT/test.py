#!/usr/bin/python3
import math
import sys
import bisect
args = sys.stdin.read().split()
TT = int(args[0])
args = args[1:]
for ca in range(1, TT + 1):
	R, T = int(args[0]), int(args[1])
	args = args[2:]
	#n = ((-(2 * r - 1) + math.sqrt((2 * r - 1) * (2 * r - 1) + 8 * t))/4);
	l = 1
	r = 2000000000000100001
	while l < r:
		n = (l + r) // 2
		if 2 * n * R + 2 * n * (n+1) - 3 * n <= T:
			l = n+1
		else:
			r = n
	print("Case #{}: {}".format(ca, l-1))
