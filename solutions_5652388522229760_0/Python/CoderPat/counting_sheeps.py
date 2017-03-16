from collections import defaultdict

def get_digits(number):
	digits = {}
	while number:
		digits[number % 10] = True
		number //= 10
	return list(digits.iterkeys())

def last_counted_number(initial_number):

	if initial_number == 0:
		return "INSOMNIA"
	digits_not_found = {}
	for i in range(10):
		digits_not_found[i] = True

	N = 1

	while True:
		for digit in get_digits(N*initial_number):
			digits_not_found.pop(digit, None)

		if not digits_not_found:
			return N*initial_number

		N += 1 

if __name__ == "__main__":
	number_cases = int(raw_input())
	for i in range(number_cases):
		print "Case #%s: %s" % (i+1, last_counted_number(int(raw_input())))
