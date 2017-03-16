TST = int(raw_input())

for _ in xrange(TST):
	r, t = map(int, raw_input().split())
	lb, rb = 0, t
	while lb + 1 < rb:
		mid = (lb + rb) >> 1
		tmp = mid * r * 2 + (mid * 2 - 1) * mid
		if tmp <= t:
			lb = mid
		else:
			rb = mid
	print "Case #" + str(_ + 1) + ": " + str(lb)
