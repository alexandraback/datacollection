import itertools

for T in xrange(int(raw_input())):
	elems = map(int, raw_input().split())
	N = elems.pop(0)
	
	print "Case #%d:" % (T + 1)
	
	subsets = []
	for num in xrange(N + 1):
		subsets.extend(list(itertools.combinations(elems, num)))
	sums = map(sum, subsets)
	d = {}
	for i, s in enumerate(sums):
		what = d.get(s)
		if what == None:
			d[s] = subsets[i]
		else:
			print " ".join(map(str, subsets[i]))
			print " ".join(map(str, what))
			break
	else:
		print "impossible"
