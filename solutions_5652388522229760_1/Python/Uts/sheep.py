def solve(N):
	if N == 0:
		return 'INSOMNIA'
	num_digits = 0
	seen_digits = [False] * 10
	n = 0
	while num_digits != 10:
		n += N
		for c in str(n):
			i = int(c)
			if not seen_digits[i]:
				seen_digits[i] = True
				num_digits += 1
	return n

T = int(raw_input())
for t in range(1, T+1):
	print "Case #%d: %s" % (t, solve(int(raw_input())))

