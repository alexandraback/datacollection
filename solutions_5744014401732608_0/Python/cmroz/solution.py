def solve(B,M):
	assert B >= 2
	edges = []
	k = B-2
	val = 1 << (k-1) if k > 0 else 1
	while k > 0:
		assert val >= 1
		if M > val:
			edges.append(k)
			M -= val
		k -= 1
		val >>= 1

	assert k == 0
	if M == 1:
		edges.append(0)
		M -= 1

	assert M >= 0
	if M != 0:
		return ("IMPOSSIBLE", None)

	mat = [[0] * B for i in xrange(B)]
	for i in xrange(B-1):
		for j in xrange(i+1,B-1):
			mat[i][j] = 1

	for e in edges:
		mat[e][B-1] = 1

	return ("POSSIBLE",mat)

if __name__ == '__main__':
	T = int(raw_input())
	for t in xrange(T):
		(B,M) = map(int, raw_input().split())
		(ret,mat) = solve(B,M)
		print "case #%d: %s" % (t+1,ret)
		if mat is not None:
			for x in mat:
				print ''.join(map(str,x))
