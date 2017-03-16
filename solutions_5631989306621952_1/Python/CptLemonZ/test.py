infile = open('A-large.in', 'r')
outfile = open('test.out', 'w')

T = int(infile.readline())

for t in range(T):
	order = list(infile.readline().strip())
	ans = order.pop(0)
	for letter in order:
		if letter < ans[0]:
			ans += letter
		else:
			ans = letter + ans
	outfile.write('Case #' + str(t+1) + ': ' + ans + '\n')