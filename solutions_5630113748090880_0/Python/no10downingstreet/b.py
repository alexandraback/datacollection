from collections import defaultdict

for t in xrange(1, input()+1):
	d = defaultdict(int)
	N = input()
	ans = []
	for row in xrange(2*N-1):
		S = raw_input().split()
		for i in S:
			d[i] += 1

	missing = []
	for i in d:
		if d[i] % 2 != 0:
			missing.append(int(i))

	missing.sort()
	print "Case #{0}:".format(t),
	for i in missing:
		print i,
	print