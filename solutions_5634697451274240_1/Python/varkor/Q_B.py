inputData = open("Q_B_input.txt", "r")
outputData = open("Q_B_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	happy = [c == "+" for c in line]
	bottom = len(happy) - 1
	swaps = 0
	while bottom >= 0:
		if not happy[bottom]:
			i = 0
			while happy[i]:
				happy[i] = not happy[i]
				i += 1
			if i > 0:
				swaps += 1
			happy = [not b for b in reversed(happy[:bottom + 1])] + happy[bottom + 1:]
			swaps += 1
		bottom -= 1
	case(number + 1, swaps)

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()