T = input()
for i in xrange(T):
	a = [int(x) for x in raw_input().split()]
	n, s, p, ans = a[0], a[1], a[2], 0
	for x in a[3:]:
		q, r = int(x / 3), int(x % 3)
		t = q + (1 if r else 0)
		if t >= p:
			ans += 1
		elif t == p - 1 and r != 1 and s > 0:
			if (r == 0 and q > 0) or r == 2:
				ans += 1
				s -= 1
	print "Case #{0}: {1}".format(i + 1, ans)
