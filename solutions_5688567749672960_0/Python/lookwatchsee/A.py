#!/usr/bin/python

T=input()
rd = lambda x: int(str(x)[::-1])
	
for t in xrange(1,T+1):
	N=input()
	d = [N]*(N+1)
	d[1]=1
	for i in xrange(2, N+1):
		j=rd(i)
#		print 'i=',i,'j=',j
		if j<i and j>0 and rd(j)==i:
			d[i]=d[j]+1
		d[i]=min(d[i], d[i-1]+1)
		
	print "Case #%d:"%t,d[N]

