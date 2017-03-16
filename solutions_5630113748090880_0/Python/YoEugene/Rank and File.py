def pushNum(numList, num):
	if num in numList:
		index = numList.index(num)
		del numList[index]
	else:
		numList.append(num)

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	m = int(raw_input())

	numList = []

	for j in xrange(2*m-1):
		n= [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case

		for l in n:
			pushNum(numList, l)

	numList.sort()

	index = 0

	while index < len(numList):
		numList[index] = str(numList[index])
		index += 1

	print "Case #{}: {}".format(i, " ".join(numList))