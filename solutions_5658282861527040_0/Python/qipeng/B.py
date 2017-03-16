with open('B-small-attempt0 (1).in') as f:
	T = int(f.readline())

	for case in xrange(T):
		data = [int(x) for x in f.readline().split()]

		A = data[0]; B = data[1]; K = data[2]

		score = 0
		for i in range(A):
			for j in range(B):
				if (i & j < K):
					score += 1

		print "Case #%d: %d" % (case+1, score)