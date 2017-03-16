# for small data

infile = open('D.in', 'r')
outfile = open('D.out', 'w')

T = int(infile.readline())

for case_num in range(1, T+1):
	K, C, S = [int(x) for x in infile.readline().split()]
	ans = []
	ptr = 0
	while ptr < K:
		pos = 0
		for layer in range(1, C+1):
			if ptr == K:
				break
			pos += ptr*(K**(C-layer))
			ptr += 1
		ans.append(pos+1)
	if len(ans) > S:
		outfile.write('Case #%d: IMPOSSIBLE\n' % case_num)
	else:
		outfile.write('Case #%d:' % case_num)
		for x in ans:
			outfile.write(' %d' % x)
		outfile.write('\n')

infile.close()
outfile.close()