with open('last.in') as f:
	data = f.read().split('\n')

with open('last.out', 'w') as f:
	for i in range(1, len(data)):
		word = data[i]
		string = word[0]
		for c in word[1:]:
			if c >= string[0]:
				string = c + string
			else:
				string = string + c
		f.write('Case #{}: {}\n'.format(i, string))