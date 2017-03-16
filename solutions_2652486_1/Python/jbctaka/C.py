#!python
# -*- coding: utf-8 -*-

import sys

sys.stdin.readline()
(R, N, M, K) = [int(x) for x in sys.stdin.readline().split()]
print "Case #1:"
for index in range(R):
	P = [int(x) for x in sys.stdin.readline().split()]
	
	counts_max = [0] * (M + 1)
	for p in P:
		counts = [0] * (M + 1)
		for n in range(M, 1, -1):
			while p % n == 0:
				p /= n
				counts[n] += 1
		counts_max = [max(counts_max[i], counts[i]) for i in range(M + 1)]
	
	ans = ("2" * counts_max[2]) + ("3" * counts_max[3]) + ("5" * counts_max[5]) + ("7" * counts_max[7])
	while len(ans) < N:
		if counts_max[8] > 0:
			ans += "8"
			counts_max[8] -= 1
		elif counts_max[6] > 0:
			ans += "6"
			counts_max[6] -= 1
		elif counts_max[4] > 0:
			ans += "4"
			counts_max[4] -= 1
		elif counts_max[7] > 0:
			ans += "7"
		elif counts_max[3] > 0:
			ans += "3"
		elif counts_max[2] > 0:
			ans += "2"
		else:
			ans += "5"
	print ans