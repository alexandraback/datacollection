import sys
from itertools import combinations

T = int(sys.stdin.readline().strip())
for t in range(T):
	n = list(map(int, sys.stdin.readline().strip().split(' ')))
	N = n[0]
	n = n[1:]
	comb = []
	for i in range(1, N + 1):
		for j in combinations(n, i):
			comb.append((sum(j), set(j)))

	found = None
	for x in comb:
		for y in comb:
			if x[0] == y[0] and not (x[1] & y[1]):
				found = x[1], y[1]
				break
		if found:
			break
	print('Case #{0}:'.format(t + 1))
	if found:
		print(' '.join(str(i) for i in found[0]))
		print(' '.join(str(i) for i in found[1]))
	else:
		print('Impossible')

