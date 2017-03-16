def solve(inp):
	count = 0
	expected = True
	for el in reversed(inp):
		if el != expected:
			count += 1
			expected = not expected
	return count


if __name__ == "__main__":
	number_of_cases = int(raw_input())
	for i in range(number_of_cases):
		inp = raw_input()
		solution = solve([letter == '+' for letter in inp])
		print "Case #{}: {}".format(i + 1, solution)