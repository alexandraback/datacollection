import math
test_count = input()
for test in xrange(test_count):
	R, total = map(int, raw_input().split())
	l = 0
	r = total;
	while l + 1 < r:
		n = (l + r) / 2
		if (2 * n * R + n + (n - 1) * 2 * n) <= total:
			l = n
		else:
			r = n
	print 'Case #%d: %d' %(test + 1, l)

