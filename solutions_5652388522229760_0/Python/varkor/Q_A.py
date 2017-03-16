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
	digits = set([str(i) for i in range(10)])
	x = int(line)
	y = x
	found = False
	if y != 0:
		for i in range(1000):
			for d in list(str(y)):
				digits.discard(d)
			if len(digits) == 0:
				case(number + 1, y)
				found = True
				break
			y = (i + 2) * x
	if not found:
		case(number + 1, "INSOMNIA")

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()