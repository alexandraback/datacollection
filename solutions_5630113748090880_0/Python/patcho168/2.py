f = open('small2.in')
T = int(f.readline().strip())

for k in range(T):
	num = int(f.readline().strip())
	numMapping = {}
	for j in range(2*num-1):
		temp = f.readline().strip()
		oneList = [int(alpha) for alpha in temp.split()]
		for i in oneList:
			if i in numMapping:
				numMapping[i]+=1
			else:
				numMapping[i] = 1
	allNum = []
	for num, value in numMapping.iteritems():
		if (value%2):
			allNum.append(num)
	allNum = sorted(allNum)
	final = " ".join((str(x) for x in allNum))
	print "Case #%d: %s" %(k+1, final)