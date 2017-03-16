
f= open("input")
NR=int(f.readline().strip())

for test in xrange(1,NR+1) :
	n=int(f.readline().strip())
	if (n==0): print("Case #%d: INSOMNIA"%test)
	else :
		dig=set(str(n))
		m=n
		while (len(dig)<10) :
			m+=n
			dig=dig.union([x for x in str(m)])
		print("Case #%d: %d"%(test,m))

