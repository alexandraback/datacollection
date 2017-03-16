t = input()
cas = 1


for i in xrange(t):
	print "Case #%d:" % cas,
	cas += 1

	s, p = map(int, raw_input().split())
	def ok(x):
		if (2 * s + 2 * x - 1) * x <= p: return True
		return False

	l = 0
	r = 10 ** 19
	while r >= l:
		mid = (l + r) / 2
		if ok(mid): l = mid + 1
		else: r = mid - 1
	print r
