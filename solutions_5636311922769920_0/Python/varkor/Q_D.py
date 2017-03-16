inputData = open("Q_D_input.txt", "r")
outputData = open("Q_D_output.txt", "w")
outputLines = []

import math

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	(K, C, S) = map(int, line.split(" "))
	if S < K / C:
		case(number + 1, "IMPOSSIBLE")
	else:
		checks = []
		i = 0
		for z in range(math.ceil(K / C)):
			sum = 0
			for level in range(C):
				sum += (i if i < K else 0) * K ** level
				i += 1
			checks.append(sum + 1)
		case(number + 1, " ".join(map(str, sorted(checks))))

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()