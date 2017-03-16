from math import sqrt
def calc(n):
	return n*(n*2+2*r-1)
tc = int(raw_input())
for ti in xrange(tc):
	r,t = map(int,raw_input().split())
	d = 0.25*(sqrt(t*8+(r*2-1)**2)+1-2*r)
	L,R = map(int,[d*0.99,d*1.01+10])
	if L<0:L=0
	while L+1<R:
		M = L+R>>1
		if calc(M)<=t:L=M
		else:R=M
	print "Case #%d: %d"%(ti+1,L)
