inputData = open("Q_A_input.txt", "r")
outputData = open("Q_A_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

j = 0
for line in inputData.read().splitlines()[1:]:
	j += 1
	parameters = line.split(" ")
	maxShyness = int(parameters[0])
	quantity = list(map(int, parameters[1]))
	cumulativeSum = 0
	extrasNeeded = 0
	for i in range(0, maxShyness + 1):
		if cumulativeSum < i:
			extrasNeeded += 1
			cumulativeSum += 1
		cumulativeSum += quantity[i]
	case(j, extrasNeeded)


outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()