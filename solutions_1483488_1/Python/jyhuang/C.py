def ndr(n, a, b):
	d = 1
	while n // d > 0: d *= 10
	d /= 10
	count = 0
	t = n
	while True:
		t = (t // d) + (t % d) * 10;
		if t == n: break
		if t >= a and t <= b and t > n: count += 1
	return count

T = input()
for t in xrange(T):
	x = [int(x) for x in raw_input().split()]
	ans = 0
	for n in xrange(x[0], x[1] + 1):
		ans += ndr(n, x[0], x[1])
	print "Case #{0}: {1}".format(t + 1, ans)
