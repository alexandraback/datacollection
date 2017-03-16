T = int(raw_input())
for test in xrange(1,T+1):
	a,b,k = map(int, raw_input().split())
	ct = 0
	for x in xrange(a):
		for y in xrange(b):
			if x&y < k:
				ct += 1
	print "Case #" + str(test) + ": " + str(ct)