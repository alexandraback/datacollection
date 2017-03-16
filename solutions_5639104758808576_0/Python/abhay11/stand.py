numRuns=int(input())
for run in range(numRuns):
	dat=input().split()
	len=int(dat[0])
	people=0
	invite=0
	for i in range(len+1):
		if people<i:
			invite+=i-people
			people=i
		people+=int(dat[1][i])
	print("Case #"+str(run+1)+": "+str(invite))