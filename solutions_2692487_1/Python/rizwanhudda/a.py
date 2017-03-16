T = input()
for case_no in range(1, T+1):
	A, N = map(int, raw_input().split())
	m = map(int, raw_input().split())
	m.sort()
	i = 0
	r = N
	c = 0
	while A>1 and i < N:
		while A <= m[i]:
			A *= 2
			A -= 1
			c += 1
		A += m[i]
		r = min(r, c + N - i - 1)
		i += 1
	print 'Case #%i: %i' % (case_no, r)