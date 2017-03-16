f=open("A-test.in","r")
g=open("A-test.out","w")

def eat(a,l):
	print a,l
	if len(l)==0:
		return 0
	if a==1:
		return len(l)

	if a>l[0]:
		return eat(a+l[0],l[1:])
	else:
		return min(eat(2*a-1,l)+1,len(l))

T=int(f.readline())
for t in xrange(1,T+1):
	[A,N]=[int(a) for a in f.readline().split()]
	l=[int(a) for a in f.readline().split()]
	l=sorted(l)
	ans=eat(A,l)
	g.write("Case #"+str(t)+": "+str(ans)+'\n')
f.close()
g.close()