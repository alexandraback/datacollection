inputData = open("Q_A_input.txt", "r")
outputData = open("Q_A_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

def scan(string, sub, n, ns):
	osub = "" + sub
	rstring = "" + string
	for c in string:
		if c in sub:
			sub = sub.replace(c, "", 1)
			rstring = rstring.replace(c, "", 1)
	if sub == "":
		ns.append(n)
		return scan(rstring, osub, n, ns)
	return string

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	ns = []
	line = scan(line, "ZERO", 0, ns)
	line = scan(line, "SIX", 6, ns)
	line = scan(line, "EIGHT", 8, ns)
	line = scan(line, "SEVEN", 7, ns)
	line = scan(line, "FIVE", 5, ns)
	line = scan(line, "THREE", 3, ns)
	line = scan(line, "FOUR", 4, ns)
	line = scan(line, "TWO", 2, ns)
	line = scan(line, "ONE", 1, ns)
	line = scan(line, "NINE", 9, ns)
	case(number + 1, "".join(sorted(map(str, ns))))

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()