inputfile = 'small.txt'
inputdata = file(inputfile,'r').readlines()
T = int(inputdata[0])
for t in range(T):
	case = inputdata[t+1].split(' ')
	N = int(case[0])
	inputs = []
	flags = []
	for j in range(N):
		inputs.append(int(case[j+1]))
		flags.append(True)
	X = sum(inputs)
	while True:
		changed = False
		average = X
		counter = 0
		for i in range(N):
			if(flags[i]):
				average = average + inputs[i]
				counter = counter + 1
		average = average*1.0/counter
		for i in range(N):
			if(flags[i]):
				if(inputs[i]>=average):
					flags[i]=False
					changed=True
		if(changed==False):
			break
	output = []
	for i in range(N):
		if(flags[i]==False):
			output.append(str(0))
		else:
			output.append(str((average-inputs[i])*100.0/X))
	print 'Case #'+str(t+1)+': '+' '.join(output)




