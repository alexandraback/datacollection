from collections import defaultdict

with open('rankfile.small') as file:
	cases = int(file.next())
	for case in xrange(cases):
		N = int(file.next())
		heights = defaultdict(int)
		for _ in xrange(2 * N - 1):
			for height in map(int, file.next().split()):
				heights[height] += 1
		missing = [height for height, count in heights.iteritems() if count % 2 == 1]
		print "Case #%d: %s" % (case+1, ' '.join(map(str, sorted(missing))))
