t = int(input())

for i in range(t):
	x = i+1
	dic1 = dict()
	dic2 = dict()
	dic3 = dict()

	j,p,s,k = map(int,input().split())

	count=0
	ans=""
	for a in range(1,(j+1)):
		for b in range(1,(p+1)):
			for c in range(1,(s+1)):
				if(not((a,b) in dic1)):
					dic1[(a,b)]=0
				if(not((b,c) in dic2)):
					dic2[(b,c)]=0
				if(not((a,c) in dic3)):
					dic3[(a,c)]=0

				if(dic1[(a,b)] >= k or dic2[(b,c)] >= k or dic3[(a,c)] >= k):
					continue
				else:
					dic1[(a,b)]+=1
					dic2[(b,c)]+=1
					dic3[(a,c)]+=1
					count+=1
					ans += str(a)+" "+str(b)+" "+str(c)+"\n"
				

	print("Case #"+str(x)+": "+str(count))
	print(ans,end="")


