for z in range(int(input())):
	n=int(input())
	a=[]
	freq=[0]*2501
	for i in range(2*n-1):
		s=list(map(int,input().split()))
		a.append(s)
		for j in s:
			freq[j]+=1
	ans=[]
	for i in range(1,2501):
		if freq[i]%2!=0:
			ans.append(i)
		if len(ans)==n:
			break
	anss=""
	for i in ans:
		anss=anss+str(i)+" "
	print("Case #"+str(z+1)+": "+anss)