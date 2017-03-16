t=input()
for i in xrange(t):
	r,c,w=map(int,raw_input().split())
	k=(c/w)*r
	if c%w==0:
		k=k+w-1
	else:
		k=k+w
	print "Case #%d: %d" %(i+1,k)
	
