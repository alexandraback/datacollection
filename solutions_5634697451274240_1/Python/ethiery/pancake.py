def solve(string):
	index = len(string)-1
	current = string[index]
	nbFlips = 1 if (current == '-') else 0
	while index >= 0:
		if string[index] != current:
			nbFlips += 1
			current = string[index]
		index -= 1
	return nbFlips 
		
nbCases = int(input())

for i in range(nbCases):
	solution = solve(input())
	print("Case #{}: {}".format(i+1, solution))