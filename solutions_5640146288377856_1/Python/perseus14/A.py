T=input()
for t in xrange(1,T+1):
	L=map(int,raw_input().split())
	print "Case #%d:"%t,
	r=L[0]
	c=L[1]
	w=L[2]
	if(w==c):
		print r-1 + w
		continue
	if(w>c/2):
		print r-1 + w+1
		continue
	z=(c/w)*r
	q=c%w
	if(q==0):
		print z + w-1
	else:
		print z+w 	
