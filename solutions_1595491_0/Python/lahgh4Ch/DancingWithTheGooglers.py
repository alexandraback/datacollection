def DancingWithTheGooglers(inputFile, outputFile):
	f = open(inputFile)
	inputLine = f.readlines()
	f.close()
	T = int(inputLine[0])
	f = open(outputFile, 'w')
	for t in range(1, T + 1):
		line = inputLine[t]
		integers = line.split()
		N = integers.pop(0)
		S = int(integers.pop(0))
		p = int(integers.pop(0))
		scores = integers
		normalLimit = p + 2 * max(0, p - 1)
		surprisingLimit = p + 2 * max(0, p - 2)
		normal = 0
		surprising = 0
		for score in scores:
			score = int(score)
			if score >= normalLimit:
				normal += 1
			elif score >= surprisingLimit:
				surprising += 1
		f.write('Case #' + str(t) + ': ' + str(normal + min(S, surprising))
				+ '\n')
	f.close()
