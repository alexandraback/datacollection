T = int(raw_input())

for t in xrange(1, T + 1):
	a,b = map(int, raw_input().split(" "))
	p = map(float, raw_input().split(" "))
	s = [1] * (len(p) + 1)
	for i in xrange(1, len(p) + 1):
		s[i] = s[i - 1] * p[i - 1]
	ans = 1 + b + 1
	for i in xrange(len(p), 0, -1):
		ans = min(ans,s[i] * (b-a+1+2*(a - i)) + (1-s[i]) * (b-a+1+2*(a-i) + b + 1))
	print "Case #%d: %f" % (t, ans)
