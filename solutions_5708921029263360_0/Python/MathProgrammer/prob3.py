from sys import*

f=open("C-small-attempt0.in","r+")
g=open("output.txt","w+")

T=int(f.readline())

for klo in range(1,1+T):
	[J,P,S,K]=[int(i) for i in f.readline().split()]
	
	table=[[[0 for i in range(S)] for i in range(P)] for i in range(J)]
	
	hjp={}
	hjs={}
	hps={}
	
	for i in range(S):
		for j in range(P):
			hps.setdefault((j,i),0)
	
	for i in range(P):
		for j in range(J):
			hjp.setdefault((j,i),0)
	
	for i in range(S):
		for j in range(J):
			hjs.setdefault((j,i),0)
	
	lis=[]
	
	for a in range(J):
		for b in range(P):
			if hjp[(a,b)]<K:
				for c in range(S):
					if hjp[(a,b)]<K and hjs[(a,c)]<K and hps[(b,c)]<K:
						if table[a][b][c]==0:
							table[a][b][c]=1
							hjs[(a,c)]+=1
							hps[(b,c)]+=1
							hjp[(a,b)]+=1
							lis.append([a,b,c])
	
	ans=sum([sum([sum(table[i][j]) for j in range(P)]) for i in range(J)])
	
	g.write("Case #{}: {}\n".format(klo,ans))
	for j in lis:
		for k in j:
			g.write("{} ".format(k+1))
		g.write("\n")


f.close()
g.close()