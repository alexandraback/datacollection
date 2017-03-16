with open('lastword.small') as file:
	cases = int(file.next())
	for case in xrange(cases):
		S = file.next().strip()
		O = ''
		for c in S:
			if c + O > O + c:
				O = c + O
			else:
				O = O + c
		print "Case #%d: %s" % (case+1, O)
