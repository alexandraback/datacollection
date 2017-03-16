
for t in xrange(input()):
	a, b, k = [int(_) for _ in raw_input().split()]
	c = 0
	for i in xrange(a):
		for j in xrange(b):
			if (i & j) < k:
				# print '<{0},{1}>: {2}'.format(a, b, a & b)
				c += 1
	print 'Case #{0}: {1}'.format(t + 1, c)
