numR=int(input())
for run in range(numR):
	data=input().split()
	
	rate=2.0
	time=0.0
	while rate*float(data[0])<(float(data[2])-float(data[0]))*float(data[1]):
		time+=float(data[0])/rate
		rate+=float(data[1])
	time+=float(data[2])/rate
	print("Case #"+str(run+1)+": "+str(time))