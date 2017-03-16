
def bsearch(r,p,x,y):
	if(x==y):
		return x
	m = (x+y+1)/2
	if (p >= (2*r-3)*m + 2*m*(m+1)):
		x = m
	else:
	 	y = m-1
#	print (x,y);
	return bsearch(r,p,x,y)
T = int(raw_input())
for t in xrange(1, T+1):
	inp = raw_input()
	r = int(inp.split()[0])
	p = int(inp.split()[1])
	print "Case #"+str(t)+": "+str(bsearch(r,p,0,1000000000000000000))
