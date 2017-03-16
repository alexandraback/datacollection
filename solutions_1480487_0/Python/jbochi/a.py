def per(j, S, X):
	C = list(reversed(sorted(S)))
	C.remove(j)

	total = X

	n = 0
	r = 0
	while C:
		n += 1
		m = C.pop()
		while C and C[-1] == m:
			n += 1
			C.pop()
		if C:
			m2 = C[-1]
		else:
			m2 = 9999

		division = (X + n * (m - j)) / float(n + 1)

		if division < 0:
			division = 0

		if j + division < m2:
			#print j + r + division
			return '%.6f' % (100 * float(r + division) / total)
		else:
			delta = m2 - j
			j_increase = max(0, delta)
			r += j_increase
			X -= j_increase + (m2 - m) * n
			j += j_increase
			#print j_increase, X, (m2 -m)			

def problem(s):
	S = map(int, s.split(' '))[1:]
	X = sum(S)
	return ' '.join(map(lambda j: per(j, S, X), S))

def solve(name):
	with open (name) as f:
		d = f.readlines()
	with open (name.replace('.in', '.out'), 'w') as o:
		for i, line in enumerate(d[1:]):
			r = "Case #%d: %s\n" % (i + 1, problem(d[i + 1]))
			print r
			o.write(r)

if __name__ == '__main__':
	solve('A-small-attempt2.in')
