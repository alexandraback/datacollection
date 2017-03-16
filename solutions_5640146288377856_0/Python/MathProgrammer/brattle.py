

f=open("A-small-attempt0.in",'r')
g=open("OUT.txt",'w')
T=int(f.readline())
for i in range(1,T+1):
	[R,C,W]=[int(i) for i in f.readline().split()]
	ans=0
	k=[0 for i in range(C)]
	while len(k)>0:
		k=k[W:]
		ans+=1
	ans*=R
	ans-=1
	ans+=W
	
	g.write("Case #{}: {}\n".format(i,ans))

g.close()
f.close()



