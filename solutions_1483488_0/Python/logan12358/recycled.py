f = open('recycled.in')
f.readline()
for t, line in enumerate(f.readlines()):
	a, b = [int(i) for i in line.split()]
	solns={}
	for n in range(a, b+1):
		N = str(n)
		for i in range(1, len(N)):
			M = N[i:]+N[:i]
			m = int(M)
			if n<m<=b:
				solns[(n, m)]=1
	print "Case #%d: %d"%(t+1, len(solns))
