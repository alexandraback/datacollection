

T=int(input())

for case in range(1,T+1):
	N=int(input())

	lists=[0 for x in range(2501)]
	for inputs in range(2*N-1):
		inp=input().split(" ")
		inp=[int(x) for x in inp]
		for num in inp:
			if lists[num]==0:
				lists[num]=1
			else:
				lists[num]=0
	mislist=[]
	for index in range(len(lists)):
		if lists[index]==1:
			mislist.append(index)
	mislist=[str(x) for x in mislist]
	output=" ".join(mislist)

	print("Case #%d: %s" %(case,output) )