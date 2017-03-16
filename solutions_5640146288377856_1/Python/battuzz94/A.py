def testcase(test_no):
	R, C, W = map(int, raw_input().split())
	ans = (C / W) * R - 1 + min(W + 1, C - W * (C / W - 1))
	print "Case #%d: %d" % (test_no, ans)

T = input()
for t in xrange(1, T + 1):
	testcase(t)