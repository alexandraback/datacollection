for t in xrange(1, input() + 1):
	n = raw_input()
	print "Case #" + str(t) + ":",
	print len([x for x in n.split("+") if x]) * 2 - [0, 1][n[0] == '-']