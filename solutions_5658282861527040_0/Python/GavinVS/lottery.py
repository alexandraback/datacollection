def lottery(A, B, K):
	num = 0
	for a in range(A):
		for b in range(B):
			if a & b < K:
				num += 1
	return num

from sys import stdin

input = stdin.read().split('\n')

for t in range(int(input[0])):
	A, B, K = map(int, input[t+1].split())

	print "Case #{0}: {1}".format(t+1, lottery(A, B, K))