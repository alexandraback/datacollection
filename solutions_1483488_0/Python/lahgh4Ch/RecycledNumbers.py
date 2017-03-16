def RecycledNumbers(A, B):
	total = 0
	examined = {}
	for x in range(A, B + 1):
		if x in examined: continue
		strX = str(x)
		num = {x: True}
		for i in range(len(strX) - 1):
			strX = strX[-1] + strX[:-1]
			if x < int(strX) <= B:
				num[int(strX)] = True
		n = len(num)
		combi = n * (n - 1) / 2
		total += combi
		for y in num:
			examined[y] = True
	return total



def calculateRecycledNumbers(inputFile, outputFile):
	f = open(inputFile)
	inputLine = f.readlines()
	f.close()
	T = int(inputLine[0])
	f = open(outputFile, 'w')
	for t in range(1, T + 1):
		A, B = inputLine[t].split()
		line = 'Case #' + str(t) + ': ' + str(RecycledNumbers(int(A), int(B)))
		f.write(line + '\n')
		print line 
	f.close()
