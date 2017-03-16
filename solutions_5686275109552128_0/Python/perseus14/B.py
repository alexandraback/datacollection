def new(L):
	m=max(L)
	M=[]
	count=0
	for x in xrange(len(L)):
		if(L[x]==m):
			if(L[x]%2):
				M.append(L[x]/2+1)
				M.append(L[x]/2)
			else:
				M.append(L[x]/2)
				M.append(L[x]/2)
			count+=1
			continue
		M.append(L[x])
	return M,count
T=input()
for t in xrange(1,T+1):
	n=input()
	L=map(int,raw_input().split())
	print "Case #%d:"%t,
	ans=max(L)
	z=0
	while(1):
		m=max(L)	
		if(m==1):
			break
		L,k=new(L)	
		m=max(L)
		z+=k
		if(ans>z+m):
			ans=z+m
	print ans
