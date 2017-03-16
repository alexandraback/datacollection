f=open("A-small-attempt0.in","r")
g=open("write_A.out","w")

def find_sqrt(n,lo,hi):
	mid=(lo+hi)/2
	if lo+1==hi or mid**2 == n:
		return mid
	elif mid**2>n:
		return find_sqrt(n,lo,mid)
	else:
		return find_sqrt(n,mid,hi)
		
T=int(f.readline())
for t in xrange(1,T+1):
	[r,k]=[int(a) for a in f.readline().split()]
	b=(2*r-1)
	c=-k
	a=2
	ans=int((-b+find_sqrt(b*b-4*a*c,0,b*b-4*a*c))/(2*a))
	g.write("Case #"+str(t)+": "+str(ans)+'\n')
f.close()
g.close()