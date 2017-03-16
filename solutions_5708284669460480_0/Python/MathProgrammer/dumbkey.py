
def GENERATE_ALL(K,S,st,keys):
	if S==0:
		return [st]
	ans=[]
	for i in keys:
		ans+=keys[i]*GENERATE_ALL(K,S-1,st+i,keys)
	return [ji for ji in ans]

f=open("B-small-attempt3.in",'r')
g=open("OUT.txt",'w')

T=int(f.readline())
for i in range(1,T+1):
	[Klen,Llen,S]=[int(j) for j in f.readline().split()]
	K=f.readline().strip()
	L=f.readline().strip()
	print(i)
	keys={i:0 for i in K}
	for j in K:
		keys[j]+=1
	
	bool=1
	for lj in L:
		if lj not in K:
			bool=0
			break
	
	if S>=Llen and bool:
		a=GENERATE_ALL(K,S,'',keys)
		E=0
		brought=0
		for st in a:
			temp=0
			for h in range(len(st)):
				if st[h:h+Llen]==L:
					E+=1
					temp+=1
			brought=max(brought,temp)
		E/=len(a)
		
		g.write("Case #{}: {}\n".format(i,brought-E))
	else:
		g.write("Case #{}: {}\n".format(i,0.0))

f.close()
g.close()
