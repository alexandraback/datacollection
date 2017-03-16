def solve(number):
	if number == 0:
		return "INSOMNIA"
	point = 1
	said_digits = set()
	while True:
		said_number = number * point
		said_digits |= set(str(said_number))
		if len(said_digits) == 10:
			return said_number
		point += 1


if __name__ == "__main__":
	number_of_cases = int(raw_input())
	for i in range(number_of_cases):
		n = int(raw_input())
		solution = solve(n)
		print "Case #{}: {}".format(i + 1, solution)