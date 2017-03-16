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
	word = ""
	for char in line:
		if word == "" or char >= word[0]:
			word = char + word
		else:
			word += char
	case(number + 1, word)

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()