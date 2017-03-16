
f = open('a.small.in')
fout = open('a.out', 'w')

numCases = int(f.readline().strip())

for numCase in range(numCases):
	s = f.readline().strip()
	result = s[0]
	for i in range(1, len(s)):
		c = s[i]
		if result[0] > c:
			result = result + c
		elif result[0] < c:
			result = c + result
		else:
			if result + c > c + result:
				result = result + c
			else:
				result = c + result
	fout.write('Case #{}: {}\n'.format(numCase+1, result))



fout.close()



