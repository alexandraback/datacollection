T=int(input())

for case in range(1,T+1):
	inp=input().split(" ")
	C=list(inp[0])
	J=list(inp[1])

	bigc=0 #>0 for Cmax, 0 for null, <0 for Jmax
	carry=0
	startC=-1
	startJ=-1

	for i in range(len(C)):
		if C[i]!='?' and startC<0:
			startC=i
		if J[i]!='?' and startJ<0:
			startJ=i

	if startC==startJ:
		if C[startC]!='?':
			if abs(int(C[startC])-int(J[startJ]))>5:
				carry=1
		if C[startC]>J[startJ]:
			bigc=1
		if C[startC]<J[startJ]:
			bigc=-1
	'''if startC>startJ:
		bigc=1
	if startC<startJ:
		bigc=-1'''



	if carry==1:
		if bigc>0:
			J[startJ-1]=1
			bigc=-1
		elif bigc<0:
			C[startC-1]=1
			bigc=1



	#fill in zeroes
	for i in range(min(startC,startJ)):
		if C[i]=='?':
			C[i]=0
		if J[i]=='?':
			J[i]=0
	#print(bigc)
	

	
	for i in range(len(C)):
		if C[i]=='?' and J[i]=='?': #both slots not filled in
			if bigc>0:
				C[i]=0
				J[i]=9
			if bigc<0:
				C[i]=9
				J[i]=0
			if bigc==0:
				C[i]=0
				J[i]=0
		elif C[i]!='?' and J[i]=='?': #fill in J
			if bigc>0:
				J[i]=9
			if bigc<0:
				J[i]=0
			if bigc==0:
				J[i]=C[i]
		elif J[i]!='?' and C[i]=='?': #fill in C
			if bigc>0:
				C[i]=0
			if bigc<0:
				C[i]=9
			if bigc==0:
				C[i]=J[i]
	

	outC="".join([str(x) for x in C])
	outJ="".join([str(x) for x in J])	
	print("Case #%d: %s %s" %(case,outC,outJ) )

