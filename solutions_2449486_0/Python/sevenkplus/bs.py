T=input()
for i in xrange(T):
	n, m = map(int,raw_input().split())
	a=[0]*n
	for j in xrange(n):
		a[j]=map(int,raw_input().split())
	print "Case #"+str(i+1)+": ", 
	vx=[0]*n
	vy=[0]*m
	for j in xrange(n):
		vx[j]=True
		for k in xrange(m):
			if a[j][k]==2:
				vx[j]=False
	for j in xrange(m):
		vy[j]=True
		for k in xrange(n):
			if a[k][j]==2:
				vy[j]=False
	F=True
	for j in xrange(n):
		for k in xrange(m):
			if a[j][k]==1 and not vx[j] and not vy[k]:
				F=False
	if F:
		print "YES"
	else:
		print "NO"