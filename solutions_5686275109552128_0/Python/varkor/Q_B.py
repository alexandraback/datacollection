inputData = open("Q_B_input.txt", "r")
outputData = open("Q_B_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

def secondLargest (l):
	maxm = max(l)
	for (i, n) in enumerate(l):
		if n == maxm:
			l.pop(i)
			break
	return max(l)

def timeLeft (plates, cost, upper):
	if cost >= upper:
		return cost
	maxm = max(plates)
	if maxm <= 1:
		return maxm
	else:
		options = [maxm]
		for num in range(1, maxm // 2 + 1):
			move = plates[:]
			move[move.index(max(move))] -= num
			move.append(num)
			options.append(1 + timeLeft(move, cost + 1, upper))
		return min(options)

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if number % 2 == 0:
		continue
	plates = list(map(int, line.split(" ")))
	case(number // 2 + 1, timeLeft(plates, 0, max(plates)))

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()