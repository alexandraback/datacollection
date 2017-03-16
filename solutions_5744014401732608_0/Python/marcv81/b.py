def solver(B, M):
	matrix = [[0 for i in xrange(B)] for j in xrange(B)]
	current = 0
	ways = 0
	while ways < M and current < B - 1:
		if current != 0:
			matrix[0][current] = 1
		matrix[current][B - 1] = 1
		ways += 1
		local = 1
		while ways < M and local < current:
			matrix[current][local] = 1
			ways += 1
			local += 1
		current += 1
	return (matrix, ways)

with open('B-small-attempt2.in', 'r') as f:
	tc_len = int(f.readline().strip())
	for tc in xrange(1, tc_len + 1):
		(B, M) = tuple(int(i) for i in f.readline().strip().split())
		(matrix, ways) = solver(B, M)
		if ways == M:
			print 'Case #' + str(tc) + ': POSSIBLE'
			for i in xrange(B):
				print ''.join(str(j) for j in matrix[i])
		else:
			print 'Case #' + str(tc) + ': IMPOSSIBLE'
