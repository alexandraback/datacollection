import sys

k = int(sys.stdin.readline())
for id, line in enumerate(sys.stdin):
	line = map(int, line.split())
	n = line[0]
	a = line[1:]
	s = sum(a)
	a = map(lambda x: x*1.0/s, a)
	print 'Case #%d:' % (id+1),
	for i in xrange(len(a)):
		l = 0.0
		r = 1.0
		while abs(l-r) > 1e-15:
			m = (l+r) * 0.5
			score = a[i] + m;
			rest = 0.0
			for j in xrange(len(a)):
				if i == j or a[j] >= score: continue
				rest += score - a[j]
			if rest > 1.0 - m:
				r = m
			else:
				l = m
		print '%.6lf' % (r*100),
	print

# print ''.join(sorted(d.keys()))
# print ''.join(sorted(d.values()))
# print d