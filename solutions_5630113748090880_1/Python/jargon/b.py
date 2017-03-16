for t in xrange(1, int(raw_input()) + 1):
	n = int(raw_input())
	counts = [0] * 2501
	for _ in xrange(2 * n - 1):
		for i in raw_input().split():
			counts[int(i)] += 1
	out = "Case #{}:".format(t)
	for i in xrange(2501):
		if counts[i] % 2:
			out += " {}".format(i)
	print out
