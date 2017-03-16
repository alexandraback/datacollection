import sys
import math

def choose(n,k):
	if k==0 or k==n: return 1.0
	ans=1.0
	for r in range(1,k+1): ans *= (n-r+1)*1.0/r
	return ans
	#return math.factorial(n)*1.0 / (math.factorial(k) * math.factorial(n-k))

def solve(n,x,y):
	z=y+abs(x)
	if z % 2 == 1: return 0. #not a possible coordinate
	z = z/2 #z is now the level
	sz =2*z*z+3*z+1 #size of levels <= z
	sz_=2*(z-1)*(z-1)+3*(z-1)+1 #size of levels < z
	if n>=sz: return 1. #the entire level is filled
	if n<=sz_: return 0. #the entire level is empty
	l=4*z+1 #size of this level
	k=n-sz_ #number of diamonds at this level
	assert sz-sz_==l
	assert 0<k<l
	if y==2*z: return 0. #would require filling level
	p=0.
	for xx in range(0,k+1):
		yy=xx+max(0,k-xx-2*z)
		if yy>y:
			p += choose(k,xx)*0.5**k
	return p

cases = int(sys.stdin.readline())
for case in range(cases):
	line=sys.stdin.readline().split()
	assert len(line)==3
	n=int(line[0])
	x=int(line[1])
	y=int(line[2])
	assert y >= 0
	assert n >= 0
	ans=solve(n,x,y)
	print 'Case #'+str(case+1)+': '+str(ans)