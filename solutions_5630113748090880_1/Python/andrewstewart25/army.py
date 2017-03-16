import sys, collections


T = int(sys.stdin.readline())

for i in xrange(1,T+1):
	n = int(sys.stdin.readline())
	lines = []
	
	total = []
	for j in xrange(2*n-1):
		line = map(int, sys.stdin.readline().split(' '))
		for l in line:
			total.append(l)
	c = collections.Counter(total)
	
	a = []
	for b in c:
		if c[b]%2 == 1:
			a.append(b)
	print "Case #%s: %s"%(i, " ".join(map(str, sorted(a))))
	