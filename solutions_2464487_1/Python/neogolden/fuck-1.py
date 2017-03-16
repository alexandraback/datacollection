inf = open('input.txt')
outf = open('output.txt','w')
t = inf.readlines()
n = int(t[0].rstrip())

def f(R,x):
	return x*(R+2*x-2)

i=0
while i<n:
	e=t[i+1].rstrip().split(' ')
	r=int(e[0])
	T=int(e[1])
	i=i+1
	le=1
	R=-(r**2)+((r+1)**2)
	ri=int((T-R)/4)
	"""while f(R,c)>T:
		c=c-1"""
	while ri-le>1:
		c=int((le+ri)/2)
		if f(R,c) > T:
			ri=c
		else:
			le=c
	g=le
	while (f(R,g)<=T):
		g=g+1
	outf.write("Case #"+str(i)+": "+str(g-1)+'\n')
inf.close()
outf.close()
	
