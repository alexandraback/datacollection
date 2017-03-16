def func(x):
	a=x[0]
	b=x[1]
	anew=""
	bnew=""
	flag=0
	flag2=0
	for i in range(len(a)):
		if a[i]=='?' and b[i]=="?":
			if flag==0:
				anew+='0'
				bnew+='0'
			elif flag==1:
				anew+='0'
				bnew+='9'
			elif flag==-1:
				anew+='9'
				bnew+='0'
		elif a[i]=="?" and b[i]!="?":
			bnew+=b[i]
			if flag==0:
				anew+=b[i]
			elif flag==1:
				anew+='0'
			elif flag==-1:
				anew+='9'				
		elif b[i]=="?" and a[i]!="?":
			anew+=a[i]
			if flag==0:
				bnew+=a[i]
			elif flag==1:
				bnew+='9'
			elif flag==-1:
				bnew+='0'				
		elif int(a[i])>int(b[i]):
			if flag2==0:
				flag=1
				flag2==1
			anew+=a[i]
			bnew+=b[i]
		elif int(a[i])<int(b[i]):
			if flag2==0:
				flag=-1
				flag2==1
			anew+=a[i]
			bnew+=b[i]
		else:
			anew+=a[i]	
			bnew+=b[i]	

	return anew,bnew

n=input()
for i in range(n):
	x=raw_input().split()
	ans=func(x)
	print "Case #"+(str(i+1))+": "+ans[0]+" "+ans[1]