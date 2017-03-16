def main():
	map = buildMap()

	numTestCases = int(raw_input())
	for testCaseNum in range(1, numTestCases+1):
		input = raw_input()
		output = ""
		for letter in input:
			output += map[letter]
		
		print "Case #" + str(testCaseNum) + ": " + output


def buildMap():
	inputs = []
	outputs = []
	
	outputs.append("our language is impossible to understand")
	outputs.append("there are twenty six factorial possibilities")
	outputs.append("so it is okay if you want to just give up")
	
	inputs.append("ejp mysljylc kd kxveddknmc re jsicpdrysi")
	inputs.append("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd")
	inputs.append("de kr kd eoya kw aej tysr re ujdr lkgc jv")
	
	inOutMap = {}
	for i in range(len(inputs)):
		inOutMap[inputs[i]] = outputs[i]
	
	letterMap = {}
	letterMap['z'] = 'q'
	letterMap['q'] = 'z'
	letterMap[' '] = ' '
	for input in inOutMap.keys():
		output = inOutMap[input]
		for n in range(len(input)):
			inLetter, outLetter = input[n], output[n]
			if inLetter == ' ':
				continue
			letterMap[outLetter] = inLetter

	reverseMap = {}
	for key in letterMap.keys():
		value = letterMap[key]
		reverseMap[value] = key

	return reverseMap

main()
