inputData = open("Q_A_input.txt", "r")
outputData = open("Q_A_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))


for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	cumulativeSum = 0
	extrasNeeded = 0
	for (i, quantity) in enumerate(map(int, line.split(" ")[1])):
		if cumulativeSum < i:
			extrasNeeded += 1
			cumulativeSum += 1
		cumulativeSum += quantity
	case(number + 1, extrasNeeded)


outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()