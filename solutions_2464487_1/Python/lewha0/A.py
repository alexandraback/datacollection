T = int(raw_input())
t0 = 1
while t0 <= T:
	buff = raw_input().split();
	rr = int(buff[0])
	tt = int(buff[1])

	left = 1
	right = tt+tt
	ret = 1
	while left <= right:
		mid = int((left + right) / 2)
		if (2 * mid * mid + 2 * mid + (2 * rr - 3) * mid) <= tt:
			left = mid + 1
			if mid > ret:
				ret = mid
		else:
			right = mid - 1
	mid = int((left + right) / 2)
	if (2 * mid * mid + 2 * mid + (2 * rr - 3) * mid) <= tt:
		if mid > ret:
			ret = mid
	print "Case #" + str(t0) + ": " + str(ret)
	t0 = t0 + 1
