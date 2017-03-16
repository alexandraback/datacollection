def solve(s,x):
	#print "SOLVE",s
	n=len(s)
	xs=sum(s)
	m=[1./n+1.0*xs/n/x-1.0*t/x for t in s]
	s2=[s[k] for k in range(len(s)) if m[k]>=0]
	if len(s)==len(s2):
		#print "DIRECT return",s
		return m
	else:
		#print "GO deeper",s2
		m2=solve(s2,x)
		mm=[0]*len(s)
		k2=0
		for k in range(len(s)):
			if m[k]>0:
				mm[k]=m2[k2]
				k2=k2+1
		assert(k2==len(m2))
		return mm
for N in range(input()):
	s=map(int,raw_input().split())
	s=s[1:]
	x=sum(s)
	m=solve(s,x)
	m=["%.6f" % (100.0*t) for t in m]
	print "Case #%d: %s" % (N+1, " ".join(m))
	