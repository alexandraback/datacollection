inputData = open("Q_B_input.txt", "r")
outputData = open("Q_B_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

n = 1
for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	(B, M) = map(int, line.split(" "))
	if M > (B - 1) * (B - 2) / 2 + 1:
		case(n, "IMPOSSIBLE")
		n += 1
	else:
		paths = 0
		matrix = [[0] * B for i in range(0, B)]
		def link(a, b):
			matrix[a][b] = 1
		stop = False
		for first in range(B - 1):
			link(first, B - 1)
			if first == 0:
				paths += 1
				if paths == M:
					break
			for second in reversed(range(first)):
				link(second, first)
				paths += 1
				if paths == M:
					stop = True
					break
			if stop:
				break
		case(n, "POSSIBLE\n" + "\n".join(list(map(lambda x: "".join(map(str, x)), matrix))))
		n += 1

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()