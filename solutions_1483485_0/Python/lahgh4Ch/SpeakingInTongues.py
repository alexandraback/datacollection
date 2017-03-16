def SpeakingInTongues(inputFile, outputFile):
	dic = {'\n': '\n', ' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', 'q': 'z'}
	f = open(inputFile)
	inputLine = f.readlines()
	f.close()
	n = int(inputLine[0])
	f = open(outputFile, 'w')
	for i in range(1, n + 1):
		f.write('Case #' + str(i) + ': ')
		line = inputLine[i]
		for j in line:
			f.write(dic[j])
	f.close()
