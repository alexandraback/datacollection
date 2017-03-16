inputData = open("Q_D_input.txt", "r")
outputData = open("Q_D_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

def divUp (x, y):
	return -(-x // y)

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	possibleToForceBroken = False
	(x, dim_1, dim_2) = map(int, line.split(" "))
	width = min(dim_1, dim_2)
	height = max(dim_1, dim_2)
	if x > 7:
		possibleToForceBroken = True
	if width * height % x != 0:
		possibleToForceBroken = True
	if (x + 1) // 2 > width or (x + 1) // 2 > height:
		possibleToForceBroken = True
	if x > width and x > height:
		possibleToForceBroken = True
	if x >= 4 and divUp((x - 1), 4) * divUp((x - 2), 4) < x and ((x + 1) // 2 == width or ((x + 1) // 2 == width - 1 and ((x - 1) % 4 == 0 or (x - 1) % 4 == 1))) and ((x + 2) // 2 == height or ((x + 2) // 2 == height - 1 and ((x - 1) % 4 == 3 or (x - 1) % 4 == 0))):
		possibleToForceBroken = True
	case(number + 1, "RICHARD" if possibleToForceBroken else "GABRIEL")

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()