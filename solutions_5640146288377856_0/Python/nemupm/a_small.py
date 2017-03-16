T = input()
for _ in xrange(T):
	r,c,w = map(int,raw_input().split())
	ans = c/w + w
	if c % w == 0:
		ans -= 1
	print "Case #%d: %d" % (_+1,ans)