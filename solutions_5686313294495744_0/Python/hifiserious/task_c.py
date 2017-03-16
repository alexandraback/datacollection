t = int(raw_input())  
for i in xrange(1, t + 1):
	num_w = int(raw_input())
	w1 = []
	w2 = []
	for x in xrange(num_w):		
		s, t = raw_input().split(" ")
		w1.append(s)
		w2.append(t)

	c = 0
	for x in xrange(num_w):
		c1 = w1.count(w1[x])
		if c1 > 1:
			c2 = w2.count(w2[x])
			if c2 > 1:
				c += 1
	print "Case #{}: {}".format(i, c)