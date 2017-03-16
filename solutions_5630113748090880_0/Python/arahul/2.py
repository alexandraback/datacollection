t=int(raw_input())
case=0
for _ in range(t):
	case+=1
	n=int(raw_input())
	arr=[0 for x in range(2501)]	
	for x in range(2*n-1):
		l=list(map(int,raw_input().split()))
		for i in l:
			arr[i]+=1
	ans=""
	for i in range(1,2501):
		if(arr[i]!=0):
			if(arr[i]%2!=0):
				ans=ans+str(i)+" "
	print("Case #"+str(case)+": "+ans)
