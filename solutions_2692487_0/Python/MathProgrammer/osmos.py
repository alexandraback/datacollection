
def REK(A,N,motes,mini,ind,curr):
	if curr>=mini:
		return(mini)
	if ind==N:
		return(min([mini,curr]))
	while ind<N and A>motes[ind]:
		A+=motes[ind]
		ind+=1
	if ind==N:
		return(min([mini,curr]))
		
	mini=REK(A,N,motes,mini,ind+1,curr+1)
	return(REK(A+A-1,N,motes,mini,ind,curr+1))

f=open("A-small-attempt0-1.in.txt","r")
fut=open("ANS.txt","w+")

T=int(f.readline())

for i in range(T):
	(A,N)=(int(j) for j in f.readline().split())
	motes=[int(k) for k in f.readline().split()]
	motes.sort()
	ans=REK(A,N,motes,10000000,0,0)
	fut.write("Case #{}: {}\n".format(i+1,ans))

f.close()
fut.close()

