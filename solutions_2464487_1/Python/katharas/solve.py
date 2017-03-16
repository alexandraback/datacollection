
def solve(r,t):
	def paint_needed(n,r):
		if n==1:
			return 2*r+1
		n-=1
		return 2*n*n+(2*r+3)*n+2*r+1
	
	a = 0
	b = t
	while b-a>1:
		n = a + (b-a)/2
		p = paint_needed(n,r)
		if p==t:
			return n
		if p>t:
			b = n
		else:
			a = n
	return a

		

tcases = int(raw_input())
for d in xrange(1,tcases+1):
	r,t = map(int,raw_input().split())
	print "Case #%d: %d" % (d,solve(r,t))
	

