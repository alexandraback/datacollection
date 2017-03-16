import math

input = open("a.in", "r")
output = open("a.out", "w")
N = int(input.readline())
for i in range(N):
	r, t = map(int, input.readline().split(' '))
	lb = 0
	ub = 1000000000000
	while ub - lb > 1:
		mb = (ub + lb) // 2
		req = 2 * mb * r + (2 * mb - 1) * mb
		if req <= t:
			lb = mb
		else:
			ub = mb;
	print("Case #{0}: {1}".format(i + 1, lb), file = output)
output.close()