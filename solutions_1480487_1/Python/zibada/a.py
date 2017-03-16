def check(s, a, i, m):
	score = a[i] + s * m
	need = 0
	for (j, x) in enumerate(a):
		if i == j: continue
		diff = (score - x) / s
		if diff < 0: continue
		need += diff + 1e-9
	return need > 1 - m

def solve():
	a = map(int, raw_input().split())[1:]
	s = sum(a)
	res = []
	for (i, x) in enumerate(a):
		l = 0.0
		r = 1.0
		for _ in xrange(100):
			m = (l + r) / 2
			if check(s, a, i, m):
				r = m
			else:
				l = m
		res.append("%.6f" % (l * 100))
	return ' '.join(res)

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, solve())
