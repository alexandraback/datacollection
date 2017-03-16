T = int(raw_input())
for test in xrange(T):
	s_max, config = raw_input().split(" ")
	s_max = int(s_max)
	config = [int(ch) for ch in config]
	standed, invited = 0, 0
	for idx, num in enumerate(config):
		if num > 0:
			if standed >= idx:
				standed += num
			else:
				invited += idx - standed
				standed += invited + num
	print "Case #%d: %d" % (test+1, invited)