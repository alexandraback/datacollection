import sys
n=int(sys.stdin.readline())
def xx(i,r):
	return 2*r*i+2*(i**2)-i
for i in xrange(n):
	r,t=sys.stdin.readline().split()
	r,t=int(r),int(t)
	low=0
	up=4000000000000
	while low<=up:
		m=(low+up)/2
		if xx(m,r)<=t: low=m
		else: up=m
		if m==(low+up)/2: break
	print('Case #%d: %d'%(i+1,low))