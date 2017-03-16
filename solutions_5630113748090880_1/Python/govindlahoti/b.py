t = input()

for q in xrange(1, t+1):
	n = input()
	aa = [map(int, raw_input().split()) for _ in xrange(2*n-1)]
	parity = [0 for _ in xrange(2501)]

	for i in aa:
		for j in i:
			parity[j] += 1

	ans = [j for j in xrange(2501) if parity[j]%2 == 1]
	ans.sort()

	print 'Case #{}: {}'.format(q, ' '.join([str(i) for i in ans]))