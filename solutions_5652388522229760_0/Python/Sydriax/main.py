def input(filename):
	lines = open(filename).read().split("\n")
	numCases = int(lines.pop(0))
	linesPerCase = int(len(lines)/numCases)
	return [[lines.pop(0) for b in range(linesPerCase)] for a in range(numCases)]


def output(filename, strings):
	file = open(filename, 'w')
	for a in range(len(strings)):
		print("Case #"+str(a+1)+": "+strings[a]+"\n")
		file.write("Case #"+str(a+1)+": "+strings[a]+"\n")

cases = input("input.txt")

strings = []
for case in cases:
	n = int(case[0])
	if n == 0:
		strings.append("INSOMNIA")
	else:
		digits = []

		number = n
		print(n)
		while len(digits) < 10:
			newDigits = list(str(number))
			for digit in newDigits:
				if digit not in digits:
					digits.append(digit)
			number += n
		strings.append(str(number-n))

output("output.txt", strings)