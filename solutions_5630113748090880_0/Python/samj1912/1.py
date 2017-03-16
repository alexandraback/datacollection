# def func(x):
# 	a=[-1 for i in range(len(x))]
# 	for i in range(len(x)):
		
# 		slow=x[i]
# 		fast=x[x[i]]
# 		while(slow!=fast):
# 			slow=x[slow]
# 		count=1
# 		slow=x[slow]
# 		fast=x[x[fast]]
# 		while(slow!=fast):
# 			slow=x[slow]
# 			fast=x[x[fast]]
# 			count+=1
# 		a[i]=count
				
t=input()
for i in range(t):
	n=input()
	a=[0 for e in range(2501)]
	ans=[]
	for k in range(2*n-1):
		b=map(int,raw_input().split())
		for j in b:
			if a[j]==0:
				a[j]=1
			else:
				a[j]=0
	for j in range(2501):
		if a[j]==1:
			ans.append(str(j))

	print "Case #"+str(i+1)+": "+" ".join(ans)		




