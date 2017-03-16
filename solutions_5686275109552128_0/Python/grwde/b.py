T=int(raw_input())

for test in range(1,T+1):
	numberdiners=int(raw_input())
	stacks=map(int,(raw_input().split()))
	closetime=min([eatingtime+sum([(stack+eatingtime-1)/eatingtime -1 for stack in stacks])
		for eatingtime in range(1,max(stacks)+1)])
	print "Case #{0}: {1}".format(test,closetime)
    
