def ensure_consistency(row1, row2):
	out = (len([i for i in range(len(row1)) if row2[i] != -1 and row1[i] != row2[i]]) == 0)
	return out

def update_column(arr, col, i):
	for j in range(len(col)):
		arr[j][i] = col[j]

def solve(lines):
	occurences = {}
	for row in lines:
		for el in row:
			if el in occurences:
				occurences[el] += 1
			else:
				occurences[el] = 1

	odd = []
	for el in occurences:
		if occurences[el] % 2 == 1:
			odd.append(el)
	return sorted(odd)



T = input()
for i in range(T):
	N = input()
	lines = []
	for _ in range(2 * N - 1):
		line = [int(n) for n in raw_input().split()]
		lines.append(line)
	sol = solve(lines)

	print 'Case #' + str(i + 1) + ': ' + str(' '.join([str(el) for el in sol]))
