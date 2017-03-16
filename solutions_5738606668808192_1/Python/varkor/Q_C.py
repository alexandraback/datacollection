inputData = open("Q_C_input.txt", "r")
outputData = open("Q_C_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

import itertools

sdm = {}
def smallest_divisor (x):
	if x in sdm:
		return sdm[x]
	i = 2
	while i ** 2 <= x:
		if x % i == 0:
			sdm[x] = i
			return i
		i += 1
		if i > 10 ** 4:
			break
	sdm[x] = x
	return x

def string_from_binary_to_base (string, base):
	if base == 10:
		return int(string)
	value = 0
	m = 1
	for d in reversed(string):
		value += int(d) * m
		m *= base
	return value

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	(N, J) = map(lambda x: int(x), line.split(" "))
	output("Case #" + str(number + 1) + ":")
	sols = 0
	for comb in itertools.product([0, 1], repeat = N - 2):
		string = "1" + "".join(map(str, comb)) + "1"
		divisors = []
		for base in range(2, 11):
			num_in_base = string_from_binary_to_base(string, base)
			div = smallest_divisor(num_in_base)
			if div < num_in_base:
				divisors.append(div)
			else:
				break
		if len(divisors) == 9:
			output(string + " " + " ".join(map(str, divisors)))
			sols += 1
			if sols == J:
				break
	if sols != J:
		print("Did not complete")

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()