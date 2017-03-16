def solve(b, m):
	ans_matrix = []
	for _ in range(b):
		ans_matrix.append([0]*b)

	ans_matrix[0][b-1] = 1
	m -= 1
	if m == 0:
		return ans_matrix

	seen = {}

	for length in range(0, b-1):

		for j in range(1, b-1):
			for k in range(j+length, b-1):
				# print length, j, k
				prefix = [0] + range(j, j+length) + [k]
					
				if len(prefix) != length + 2:
					continue

				if ''.join(map(str, prefix)) in seen:
					continue
				seen[''.join(map(str, prefix))] = 1
				print prefix
				for edge in range(len(prefix) - 1):
					print 'adding edges from {0} to {1}'.format(prefix[edge], prefix[edge+1])
					ans_matrix[prefix[edge]][prefix[edge+1]] = 1
				print 'adding edges from {0} to {1}'.format(prefix[len(prefix)-1], b-1)
				ans_matrix[prefix[len(prefix)-1]][b-1] = 1
				m -= 1
				if m == 0:
					return ans_matrix

	if m > 0:
		print 'm is {0}'.format(m)
		for e in ans_matrix:
			print e
		return 'IMPOSSIBLE'

	raise Exception('!')

# print solve(5, 4)
# print solve(2, 1)
# print solve(4, 20)
# print solve(4, 7)
# print solve(5, 10)
# print solve(5, 6)
# print solve(4, 5)
# print solve(5, 5)
# print solve(6, 15)

f_out = open('B_output.txt', 'w')
f_in = open('B-small-attempt2.in', 'r')

lines = [line.strip() for line in f_in.readlines()][1:]
for idx in range(0, len(lines), 1):
	b, m = map(int, lines[idx].split())
	
	s = solve(b, m)

	if s == 'IMPOSSIBLE':
		f_out.write("Case #{0}: {1}\n".format(idx+1, s))
	else:
		ans = ''
		for row in s:
			ans += ''.join(map(str, row)) + '\n'
		ans = ans.strip()
		f_out.write("Case #{0}: {1}\n{2}\n".format(idx+1, 'POSSIBLE', ans))

f_out.close()
