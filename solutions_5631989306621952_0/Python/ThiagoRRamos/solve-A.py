def solve(word):
	if len(word) == 0:
		return ''
	letter, index = max((b,a) for a,b in enumerate(word))
	return letter + solve(word[0:index]) + word[index + 1:]


if __name__ == "__main__":
	number_of_cases = int(raw_input())
	for i in range(number_of_cases):
		inp = raw_input()
		solution = solve(inp)
		print "Case #{}: {}".format(i + 1, solution)