for cases in xrange(input()):
	nput = raw_input()
	frac = nput.split(" ")
	R = int(frac[0])
	C = int(frac[1])
	W = int(frac[2])
	fl = int(float(C)/float(W))
	ret = R * fl + W-1
	if(float(C)/float(W)!=fl):
		ret += 1
	print "Case #"+str(cases+1)+": "+str(ret)

