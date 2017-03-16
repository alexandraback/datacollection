for T in xrange(1,1+int(raw_input())):
	e,r,n=map(int,raw_input().split())
	v=map(int,raw_input().split())
	a=[[0]*(e+1)for _ in xrange(n+1)]
	for i in xrange(n):
		for start in xrange(e+1):
			for end in xrange(start+1):
				rec=min(e,end+r)
				a[i+1][rec]=max(a[i+1][rec],a[i][start]+(start-end)*v[i])
	print"Case #%d: %d"%(T,max(a[-1]))
