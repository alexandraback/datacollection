def solve(lists_of_lists):
	counter = {}
	for array in lists_of_lists:
		for el in array:
			if el not in counter:
				counter[el] = 1
			else:
				counter[el]+= 1
	missing = [el for el in counter if counter[el] %2 == 1]
	return " ".join(str(x) for x in sorted(missing))


if __name__ == "__main__":
	number_of_cases = int(raw_input())
	for i in range(number_of_cases):
		inp = int(raw_input())
		lines = [[int(x) for x in raw_input().split()] for a in range(2*inp - 1)]
		solution = solve(lines)
		print "Case #{}: {}".format(i + 1, solution)