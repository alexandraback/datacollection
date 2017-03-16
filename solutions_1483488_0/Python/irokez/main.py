import sys

def _gen_pairs(n, d):
	base = 10
	for b in range(d):
		least = n % base
		great = int(n / base)
		recyled = lease * base + great

def gen_pairs(n, d):
	pairs = []
	for i in range(1, d + 1):
		pair = n[-i:] + n[:-i]
		if pair[0] == '0':
			continue
		if pair < n:
			continue
		pairs.append(pair)
	return pairs

T = int(sys.stdin.readline().strip())
for t in range(T):
	A, B = map(int, sys.stdin.readline().strip().split(' '))
	if A < 10:
		print('Case #{0}: {1}'.format(t + 1, 0))
		continue
	d = 1
	base = 10
	while A >= base:
		base *= 10
		d += 1

	pairs = set()
	strB = str(B)
	for i in range(A, B + 1):
		n = str(i)
		for i in range(1, d + 1):
			pair = n[-i:] + n[:-i]
			if pair[0] == '0' or pair <= n or pair > strB:
				continue
			pairs.add((n, pair))
	
	print('Case #{0}: {1}'.format(t + 1, len(pairs)))
