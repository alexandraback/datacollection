def add(d,reach):
	array = reach[:]
	for k in xrange(len(reach)):
		if(reach[k]==1 and k+d < len(reach)):
			array[k+d]=1
	return array
		
for cases in xrange(input()):
	nput = raw_input()
	frac = nput.split(" ")
	C = int(frac[0])
	D = int(frac[1])
	V = int(frac[2])
	den = raw_input()
	den = den.split(" ")
	den = [int(x) for x in den]
	reach = [0]*(V+1)
	reach[0]=1	
	counter = 0
	for d in den:
		reach = add(d,reach)	
	k = 0
	while(k<len(reach)):
		if(reach[k]==0):
			reach = add(k,reach)
			counter += 1
		k+=1
	ret = counter 
	print "Case #"+str(cases+1)+": "+str(ret)

