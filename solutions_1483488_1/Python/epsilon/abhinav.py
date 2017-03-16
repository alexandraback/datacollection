cases=int(input())

pntr=0

while pntr<cases:
	pntr+=1
	[sm,lr]=map(int,input().split())
	status=[0]*(lr-sm+1)
	total=0
	for number in range(sm,lr+1):
		if status[number-sm]:
			continue
		num=str(number)
		count=1
		status[number-sm]=1
		for i in range(1,len(num)):
			temp=int(num[i:]+num[:i])
			if sm<=temp and temp<=lr and (not status[temp-sm]):
				count+=1
				status[temp-sm]=1
		total+=count*(count-1)//2
	print("Case #"+str(pntr)+":",str(total))
