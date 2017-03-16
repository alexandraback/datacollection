t=int(raw_input())
for i in xrange(1,t+1):
	r,c,w=map(int,raw_input().split())
	if c%w==0:
		x=c/w
	else:
		x=(c//w)+1
	print "Case #%d: %d" %(i,r*(x+w-1))
