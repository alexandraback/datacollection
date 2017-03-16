import sys
cases = sys.stdin.readlines()

for case in range(1, int(cases[0].strip()) + 1):
	K, C, S = map(int, cases[case].split())

	origs = range(K)
	partitions = []
	while origs:
		partitions.append(origs[:C])
		origs = origs[C:]

	if S < len(partitions):
		print 'Case #{}: IMPOSSIBLE'.format(case)
		continue

	samples = []
	for partition in partitions:
		while len(partition) < C:
			partition.append(0)
		inc = 0
		for p in partition:
			inc = inc * K + p
		samples.append(inc + 1)
	print 'Case #{}: {}'.format(case, ' '.join(map(str, samples)))