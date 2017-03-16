T=input()
def G(r,x,t):
	t-=(r*2+1+r*2+4*x-3)*x/2
	return t>=0

def F():
	r,t=map(int,raw_input().split())
	L=0
	R=100000000000000
	while L<R-1:
		M=L+R>>1
		if G(r,M,t):
			L=M
		else:
		 	R=M
	print "Case #%d: %d"%(i+1,L)
for i in range(T):
	F()
	
