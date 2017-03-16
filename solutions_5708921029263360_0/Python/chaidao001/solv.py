import random

def solve(inputs):
	inputs = [int(i) for i in inputs.split()]

	[j, p, s, k] = inputs

	comb = dict()
	result = []

	js = list(range(1, j + 1))
	ps = list(range(1, p + 1))
	ks = list(range(1, s + 1))

	random.shuffle(js)
	random.shuffle(ps)
	random.shuffle(ks)

	for a in js:
		for b in ps:
			for c in ks:
				if addToDict(a, b, c, k, comb):
					result.append(str(a) + " " + str(b) + " " + str(c))

	return result


def addToDict(a, b, c, k, comb):
	c = [str(a) + str(b) + 'x', 'x' + str(b) + str(c), str(a) + 'x' + str(c)]

	for i in c:
		if i in comb and comb[i] >= k:
			return False

	for i in c:
		if i not in comb:
			comb[i] = 1
		else:
			comb[i] += 1

	return True


input_file_name = "../C-small-attempt1.in"
output_file_name = "output.out"


with open(input_file_name, "r") as input:
	number_cases = int(input.readline())

	with open(output_file_name, "w") as output:

		for i in range(number_cases):

			inputs = input.readline().strip()

			results = solve(inputs)

			if results is None:
				print("NOOOOOOOO")
			else:
				output.write("Case #" + str(i + 1) + ": " + str(len(results)) + "\n")
				for result in results:
					output.write(result + "\n")

