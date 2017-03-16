def solve():
	[c,f,x] = map(float, raw_input().split())
	t = x/2;
	r = 2;
	tr = 0;
	while tr <= t:
		t2 = tr + x/r;
		if t2 < t:
			t = t2
		tr += c/r
		r += f


	return t

tc = int(raw_input())
for ti in xrange(tc):
	print "Case #%d: %.7f" % (ti+1,solve())