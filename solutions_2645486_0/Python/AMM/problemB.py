f=open("B-small-attempt1.in","r")
g=open("write_B.out","w")
T=int(f.readline())
for t in xrange(1,T+1):
	[E,R,n]=[int(x) for x in f.readline().split()]
	V=[int(x) for x in f.readline().split()]
	ans=0
	keep=[]
		
	for i in range(2**n):
		#string rep binary
		s='0'*(n-len("{0:b}".format(i)))+"{0:b}".format(i)
		L=[]#list of x_i
		sumUpto=0
		for i in range(len(s)-1):
			if s[i]=='1':
				L.append(min(E,E-sumUpto+R*i))
				sumUpto+=min(E,E-sumUpto+R*i)
			else:
				L.append(max((i+1)*R-sumUpto,0))
				sumUpto+=max((i+1)*R-sumUpto,0)
		L.append(E+(len(s)-1)*R-sumUpto)
		
		#calculate
		newL=[L[i]*V[i] for i in range(n)]
		check=sum(newL)
		if check>ans:
			keep=L
			ans=check

	g.write("Case #"+str(t)+": "+str(ans)+'\n')
f.close()
g.close()