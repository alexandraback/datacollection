
f = open('b.large.in')
fout = open('b.out', 'w')

numCases = int(f.readline().strip())

for numCase in range(numCases):
	n = int(f.readline().strip())
	s = {}
	for i in range(2*n-1):
		cs = f.readline().split()
		for c in cs:
			# print c
			if c not in s:
				s[c] = 0
			s[c] = s[c] + 1
	# print s

	result = []
	for c in s:
		if s[c] % 2  == 1:
			result.append(int(c))

	result.sort()
	# print ' '.join(result)
	fout.write('Case #{}: {}\n'.format(numCase+1, ' '.join([str(i) for i in result])))



fout.close()



