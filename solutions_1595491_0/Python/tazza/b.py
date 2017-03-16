T=int(raw_input())
for tt in range(T):
	line=map(int,raw_input().split())
	n=line[0]
	s=line[1]
	p=line[2]
	store=[]
	for i in range(n):
		store.append(line[i+3])
	store.sort()
	res=0
	for i in range(len(store)-1,-1,-1):
		if store[i]>=3*p-2 and store[i]>=p:
			res+=1
			continue
		if store[i]>=p and store[i]>=3*p-4 and s>0:
			res+=1
			s-=1
	print 'Case #%d:'%(tt+1),res

