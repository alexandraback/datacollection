T = int(raw_input())
for t in xrange(T):
	l = [int(x) for x in raw_input().split(' ')]
	N = l[0]
	S = l[1]
	p = l[2]
	nns = 0
	ns = 0
	l = l[3:]
	for x in l:
		if x == 0:
			if p == 0:
				nns+=1
		elif 3*p <= x+2:
			nns += 1
		elif x > 1 and 3*p <= x+4:
			ns += 1
	ns = min(ns, S)
	print "Case #%d: %d" % (t+1, nns + ns)
