for N in range(input()):
	[A,B]=[int(x) for x in raw_input().split()]
	count=[]
	for n in range(A,B):
		ns=str(n)
		for s in range(1,len(ns)):
			#print ns[s:],ns[:s]
			m=int(ns[s:]+ns[:s])
			if m>n and m<=B: count+=[(n,m)]
	print "Case #%d: %d" % (N+1,len(set(count)))

