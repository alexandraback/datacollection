t = int(raw_input())

for case in xrange(1, t+1):
	a, b, k = map(int, raw_input().split())
	count = 0
	for i in xrange(a):
		for j in xrange(b):
			if (i & j) < k:
				count += 1
	print "Case #%d: %d" % (case, count)
