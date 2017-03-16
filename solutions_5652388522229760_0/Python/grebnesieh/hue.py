for t in xrange(1, input() + 1):
	n = input()
	print "Case #" + str(t) + ":",
	if not n:
		print "INSOMNIA"
	else:
		j = n
		s = set(str(j))
		while len(s) < 10:
			j += n
			s |= set(str(j))
		print j