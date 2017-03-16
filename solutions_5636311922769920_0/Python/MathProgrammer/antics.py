
def SOLVE(K,C,S):
	ans=""
	for n in range(1,K+1):
		pos=0
		for c in range(C):
			pos+=(n-1)*(K**c)
		pos+=1
		ans+=str(pos)+" "
	
	return ans
		

f=open("D-small-attempt0.in","r")
g=open("google.out","w+")
T=int(f.readline())

for i in range(T):
	[K,C,S]=[int(j) for j in f.readline().split()]
	ans=SOLVE(K,C,S)
	g.write("Case #{}: {}\n".format(i+1,ans))

g.close()
f.close()




