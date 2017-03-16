import sys

# Read number of cases
for tc in xrange(1, int(sys.stdin.readline())+1):
	# Read integers from a line
	J = [int(w) for w in sys.stdin.readline().split()]
	N = J[0]
	J = J[1:]
	X = sum( J )
	results = []

	for j in J:
		occurrences = J.count(j)
		# # print "Handling ", j, occurrences
		lesser = [ x for x in J if x < j ]
		lesser_or_equal = [ x for x in J if x <= j ]

		rest = X
		# print "X", X

		for l in lesser_or_equal:
			rest -= j - l 
		to_add = 0
		lev = j
		elems = len(lesser_or_equal)
		while rest > 0:
			# print "Rest:",rest, lev, elems
			bigger = [ x for x in J if x > lev ]
			bigger.sort()

			d = rest * 1.0 / elems
			if len(bigger) == 0:
				to_add += d
				rest = 0
			else:
				minorbigger = bigger[0]
				countmb = bigger.count( minorbigger )
				if lev + d > minorbigger:
					d = minorbigger - lev
					rest -= d * elems
					to_add += d

					elems += countmb
					lev = minorbigger
				else:
					to_add += d
					rest = 0
		results.append( "%.6f" % (to_add * 100.0/ X) )

	print 'Case #%d: %s' % (tc, " ".join(results) )
