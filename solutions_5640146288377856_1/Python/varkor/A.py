inputData = open("A.in", "r")
outputData = open("A.out", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))


for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	(R, C, W) = map(int, line.split(" "))
	print(R, C, W)
	print(max(0, (C // W) * R - (1 + (1 if C % W < (W - 1) else 0))), min(C, W + 1))
	case(number + 1, (C // W) * R - 1 + W + (1 if C % W != 0 else 0))


outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()