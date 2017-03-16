def solve(n):
	if n < 10: return n
	s = str(n)
	l = len(s)
	base = solve(10 ** (l - 1) - 1) + 1
	left = int(s[:l/2])
	rleft = int("".join(reversed(s[:l/2])))
	right = int(s[l/2:])
	if rleft == 1: rleft = 0
	if right == 0:
		if rleft == 0: return base
		left -= 1
		right = 10 ** ((l + 1) / 2)
		if left == 10 ** ((l / 2) - 1):
			return base + right
		rleft = int("".join(reversed(str(left))))
		return base + rleft + right
		
	return base + rleft + right
	

for i in xrange(input()):
	n = int(raw_input())
	print "Case #%d: %d" % (i + 1, solve(n))
