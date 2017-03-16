def get_solution(string):
	j, p, s, k = string.split()
	j = int(j)
	p = int(p)
	s = int(s)
	k = int(k)

	pattern_count = {}

	all_poss = []
	for a in range(1, j+1):
		for b in range(1, p+1):
			for c in range(1, s+1):
				jp = '%d%d*' % (a, b)
				js = '%d*%d' % (a, c)
				ps = '*%d%d' % (b, c)
				
				if not pattern_count.has_key(jp):
					pattern_count[jp] = 0
				if not pattern_count.has_key(js):
					pattern_count[js] = 0
				if not pattern_count.has_key(ps):
					pattern_count[ps] = 0
				if pattern_count[jp] == k or pattern_count[js] == k or pattern_count[ps] == k:
					pass
				else:
					all_poss.append([str(a), str(b), str(c)])
					pattern_count[jp] += 1
					pattern_count[js] += 1
					pattern_count[ps] += 1

	return all_poss


t = int(raw_input())

for i in range(t):
    string = raw_input()
    sol = get_solution(string)
    print "Case #%d: %s" % (i+1, str(len(sol)))
    for i in sol:
    	print ' '.join(i)