import itertools

def is_divisible(string, base, divisor):
	return int(string, base) % divisor == 0

def is_good(string, base):
	return is_divisible(string, base, base + 1)

def is_very_good(string):
	for base in range(2, 11):
		if not is_good(string, base):
			return False
	return True  	 	

def generate_string(total_elements, places_with_ones):
	pointer = 0
	for el in range(total_elements):
		if pointer < len(places_with_ones) and el == places_with_ones[pointer]:
			yield "1"
			pointer += 1
		else:
			yield "0"


def generate_strings(total_elements, ones):
	for places_with_ones in itertools.combinations(range(total_elements), ones):
		string = "".join(generate_string(total_elements, places_with_ones))
		yield string

def generate_from_odd_and_even_arrays(odd, even):
	yield "1"
	for i in range(len(odd)):
		yield odd[i]
		yield even[i]
	yield "1"

def generate(N, J):
	count = 0
	for number_of_ones in range(J):
		for even, odd in zip(generate_strings(N, number_of_ones), generate_strings(N, number_of_ones)):
			string = "".join(generate_from_odd_and_even_arrays(odd, even))
			yield string
			count += 1
			if count >= J:
				break
		if count >= J:
			break

def solve(N, J):
	numbers = list(generate(N/2 - 1, J))
	assert all([is_very_good(elem) for elem in numbers])
	assert len(numbers) == J
	print "Case #1:"
	for elem in numbers:
		print "{} 3 4 5 6 7 8 9 10 11".format(elem)

solve(16, 50)
#solve(32, 500)