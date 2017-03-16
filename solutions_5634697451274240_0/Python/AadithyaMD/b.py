t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	s = raw_input()
	l = []
	for ch in s:
		if ch == '+':
			l.append(True)
		elif ch == '-':
			l.append(False)

	n = len(l)
	c = 0
	while len(l)>0:
		if l[n-1] == True:
			l.pop()
			n=n-1
			continue

		# now all the correctly placed pankakes at bottom r removed from further calculation
		#stack bottom has incorrect pancake
		
		if l[0] == False:			# if stack top is also false flip it
			l.reverse()
			for x in xrange(0,n):
				l[x] = (not l[x])
			c=c+1
			continue

		# now if stack top is true
		for x in xrange(0,n):
			if l[x] == True:
				l[x]=False
			else:
				c=c+1
				break

	print "Case #{}: {}".format(i,c)