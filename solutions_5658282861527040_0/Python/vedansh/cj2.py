t=input()
for i in xrange(t):
	a,b,k=map(int,raw_input().split())
	q=0
	for j in xrange(a):
		for z in xrange(b):
			if j&z < k:
				q=q+1
	print "Case #%d: %d" %(i+1,q) 
