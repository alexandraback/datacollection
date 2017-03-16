f=open(r'A_smallinput.in', 'r')
c = f.readline()
c = c.rsplit( )[0]
c = int(c)
for i in range(1, c+1) :
	s = []
	ts = 0
	fts = 1.0
	res = []
	line=f.readline()
	line=line.rstrip("\n\r ")
	line=line.split(' ')
	N = int(line.pop(0))
	n = N
	for j in xrange(N):
		s.append(float(line[j]))
	for j in xrange(N):
		ts += s[j]
	for j in xrange(N):	
		r = 100*(2.0/N - float(s[j]/ts))
		if r < 0:
			res.append(0.0)
		else:
			res.append(r)
	#print res		
	n = res.count(0.0)
	#print n
	if n != 0:
		for j in xrange(N):
			if res[j] != 0.0 :
				fts += float(s[j]/ts)
		#print fts		
		#print n
		for j in xrange(N):
			if res[j] !=0:
				res[j] = 100*(float(fts/(N-n)) - float(s[j]/ts))

	print 'Case #{0}: '.format(i),
	for j in xrange(N):
		print res[j],
	print ''	
