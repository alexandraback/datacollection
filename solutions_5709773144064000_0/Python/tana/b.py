n = int(raw_input())
for i in xrange(n):
	(c,f,x) = map(float,raw_input().split())
	k = max(int((x/c)-(2.0/f))-1, 0)
	z = sum([c/(2.0+j*f) for j in xrange(k+1)])
	z += x/(2.0+(k+1)*f)
	z = min(z,x/2)
	print 'Case #'+str(i+1)+': '+str(z)
