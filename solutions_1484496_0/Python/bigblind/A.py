from __future__ import division

import itertools
inp = open('A.in')
out = open('A.out','w')
cases = int(inp.readline())



for case in xrange(1,cases+1):
	numbers = [int(x) for x in inp.readline().split()[1:]]
	print "case "+str(case)
	out.write("Case #"+str(case)+":\n")
	setlen = 1
	numlen = len(numbers)
	broken = False
	while setlen < numlen - 1:
		print "set length "+str(setlen)
		if setlen == 1:
			sets = [[x] for x in numbers]
		else:
			sets = list(sets)
			sets += list(itertools.combinations(numbers,setlen))
		
		if setlen > 1:
			for sets in itertools.combinations(sets,2):
				if sum(sets[0]) == sum(sets[1]):
					broken = True
					out.write(" ".join([str(x) for x in sets[0]]) + "\n")
					out.write(" ".join([str(x) for x in sets[1]]) + "\n")
					break
		
		if broken:
			break
		setlen += 1
	if not broken:
		out.write("Impossible\n")
	