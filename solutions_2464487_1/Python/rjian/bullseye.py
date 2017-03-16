import math
testcases = int(raw_input())
for test in xrange(testcases):
	r, t = map(int, raw_input().split(" "))
	a = (-(2*r - 1) - math.sqrt((2*r - 1)**2 + 4 * 2 * t )) / 4.0
	b = (-(2*r - 1) + math.sqrt((2*r - 1)**2 + 4 * 2 * t )) / 4.0
	if a < 0:
		ans = b
	else:
		ans = a
	ans = int(ans)
	while 2 * r * ans + ans + 4 * ans * (ans - 1) / 2.0 > t:
		ans -= 1
	while 2 * r * (ans + 1) + (ans + 1) + 4 * (ans + 1) * (ans) / 2.0 < t:
		ans += 1
	print "Case #%d: %d" % (test + 1, ans)