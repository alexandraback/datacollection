#input_set = "A-very-small.in"
#input_set = "A-small-gen.in"
#input_set = "A-large-gen.in"
input_set = "A-small-attempt0.in"

def max_sheep_number(n):
	numbers = set()
	max_attempts = 1000000
	for x in range(10):
		numbers.add(str(x))
	attempt = 1
	while attempt < max_attempts:
		number = n * attempt
		for x in str(number):
			numbers.discard(x)
		if len(numbers) == 0:
			return number
		attempt += 1
	return "INSOMNIA"

with open(input_set) as cases:
	case_number = 0
	next(cases)

	for data in cases:
		case_number += 1
		sheep_number = int(data)
		if sheep_number == 0:
			result = "INSOMNIA"
		else:
			result = max_sheep_number(sheep_number)
		print "Case #{}: {}".format(case_number, result)