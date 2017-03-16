
def flipplus(N): #Actually cuts off the pluses beforehand
	if len(N)==0:
		return ""
	i=0
	if N[0]=="-":
		return N
	while N[i]=="+":
		i+=1
		if i==len(N):
			return ""
	return N[i:]

def flipstack(N):
	if len(N)==0:
		return ""
	ans=""
	hs={"+":"-", "-":"+"}
	for i in range(len(N)-1,-1,-1):
		ans+=hs[N[i]]
	return ans

def cutoffplus(N):
	if len(N)==0:
		return ""
	i=len(N)-1
	while N[i]=="+":
		i-=1
		if i<0:
			return ""
	return N[:i+1]

def SOLVE(N):
	moves=0
	N=cutoffplus(N)
	while len(N)>0:
		#Flip top pluses
		if N[0]=="+":
			moves+=1
			N=flipplus(N)
		
		#Flip stack
		N=flipstack(N)
		moves+=1
		
		#Cutoff pluses
		N=cutoffplus(N)
		
	return moves

f=open("B-small-attempt0.in","r")
g=open("google.out","w+")
T=int(f.readline())

for i in range(T):
	N=f.readline().strip()
	ans=SOLVE(N)
	g.write("Case #{}: {}\n".format(i+1,ans))

g.close()
f.close()




