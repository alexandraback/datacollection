inputData = open("Q_C_input.txt", "r")
outputData = open("Q_C_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

def reduce (string):
	restring = string
	for combo in ["ijk", "jki", "kij"]:
		restring = restring.replace(combo, "-")
	for combo in ["kji", "jik", "ikj"]:
		restring = restring.replace(combo, "")
	for combo in [x * 2 for x in ["i", "j", "k"]]:
		restring = restring.replace(combo, "-")
	restring = restring.replace("ij", "k").replace("jk", "i").replace("ki", "j");
	restring = restring.replace("ji", "-k").replace("kj", "-i").replace("ik", "-j");
	neg = restring.count("-") % 2 != 0
	restring = restring.replace("-", "")
	return (restring != string, restring, neg)

def reducem (string):
	neg = False
	if len(string) > 1:
		while True:
			red = reduce(string)
			if red[2]:
					neg = not neg
			if red[0]:
				string = red[1]
			else:
				break
	return (string, neg)

def quaternionMultiply (units):
	value = 1
	(units, neg) = reducem(units)
	for unit in map(lambda x: 2 if x == "i" else (3 if x == "j" else 4), units):
		if value == 1 or unit == 1:
			value = unit
		elif value == 2:
			value = -1 if unit == 2 else (4 if unit == 3 else -3)
		elif value == 3:
			value = -1 if unit == 3 else (2 if unit == 4 else -4)
		elif value == 4:
			value = -1 if unit == 4 else (3 if unit == 2 else -2)
		if value < 0:
			value = -value
			neg = not neg
	if neg:
		value = -value
	return value

def sign (x):
	if x > 0:
		return 1
	elif x == 0:
		return 0
	else:
		return -1

def searchFor_ijk (string, limit):
	split_1r = ""
	for split_1 in range(1, min(limit, len(string) - 1)):
		split_1r = split_1r + string[split_1 - 1]
		gah = reducem(split_1r)
		split_1r = gah[0] + ("-" if gah[1] else "")
		if quaternionMultiply(split_1r) == 2:
			rest = string[split_1:]
			if rest != rest[0] * len(rest):
				for split_2 in range(split_1 + 1, len(string)):
					if quaternionMultiply(string[split_1:split_2]) == 3:
						return True
	return False

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if number % 2 == 0:
		repetitions = int(line.split(" ")[1])
		continue
	if repetitions > 4:
		string = line * 4 + line * ((repetitions - 4) % 4)
		limit = len(line) * 4
	else:
		string = line * repetitions
		limit = len(string)
	tstring = (line * (repetitions % 4))
	foundSol = True
	if line == line[0] * len(line) or quaternionMultiply(tstring) != -1:
		foundSol = False
	else:
		foundSol = searchFor_ijk(string, limit)
	case(number // 2 + 1, "YES" if foundSol else "NO")

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()