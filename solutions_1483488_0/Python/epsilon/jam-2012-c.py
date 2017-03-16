cases=int(input())

pntr=0

while pntr<cases:
	pntr+=1
	[sm,lr]=map(int,input().split())
	dic={}
	count=0
	for i in range(sm,lr+1):
		dic[i]=0
	for num in range(sm,lr+1):
		if dic[num]==0:
			dic[num]=1
			temp=str(num)
			lgth=len(temp)
			ls=set([num])
			cntr=0
			while cntr<lgth:
				cntr+=1
				temp=temp[1:]+temp[0]
				number=int(temp)
				if number<lr+1 and sm<=number:
					ls.add(number)
					dic[number]=1
			count+=len(ls)*(len(ls)-1)//2
		else:
			continue
	print('Case #'+str(pntr)+':',str(count))
