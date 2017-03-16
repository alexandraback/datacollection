f = open('A-small-attempt0.in', 'r')
T = int(f.readline())
for testCase in range(1, T+1):
	(sMax, s) = f.readline().split()

	numClapping = int(s[0])
	numNeeded = 0
	for i in range(1, int(sMax) + 1):
		if (numClapping < i):
			temp = i - numClapping
			numNeeded += temp
			numClapping += temp

		numClapping += int(s[i])

	print "Case #%d: %d" % (testCase, numNeeded)


