t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	k,c,s = [int(s) for s in raw_input().split(" ")]
	print "Case #{}:".format(i),
	n = k//c
	if k % c > 0:
		n = n+1
	if s < n :
		print " IMPOSSIBLE"
		continue

	i=0
	while i < k:
		#c1 = c 
		p = i 
		c1=c-1
		i = i+1
		while(c1>0):
			p=p*k 
			if i<k:
				p=p+i
				i = i+1
			c1 = c1-1
		print " {}".format(p+1),
	print ''