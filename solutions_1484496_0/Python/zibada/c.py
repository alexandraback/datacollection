def solve():
	a = sorted(map(int, raw_input().split())[1:])
	res = {}
	for m in xrange(1 << 20):
		s = 0
		for j, x in enumerate(a):
			if ((m >> j) & 1) == 0: continue
			s += x
		if s in res:
			m2 = res[s]
			set1 = []
			set2 = []
			for j, x in enumerate(a):
				if (m >> j) & 1:
					set1.append(x)
				if (m2 >> j) & 1:
					set2.append(x)
			return ' '.join(map(str, set1)) + "\n" + ' '.join(map(str, set2))				
		res[s] = m
	return "Impossible"
		

for i in xrange(input()):
	print "Case #%d:\n%s" % (i + 1, solve())
