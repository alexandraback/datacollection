def remove_char(s, c):
	return s.replace(c, '', 1)

def remove_word(s, word):
	for c in word:
		s = remove_char(s, c)
	return s

def solve(s):
	digits = []
	while 'Z' in s:
		s = remove_word(s, 'ZERO')
		digits.append(0)
	while 'X' in s:
		s = remove_word(s, 'SIX')
		digits.append(6)
	while 'G' in s:
		s = remove_word(s, 'EIGHT')
		digits.append(8)
	while 'S' in s and 'V' in s:
		s = remove_word(s, 'SEVEN')
		digits.append(7)
	while 'V' in s:
		s = remove_word(s, 'FIVE')
		digits.append(5)
	while 'F' in s:
		s = remove_word(s, 'FOUR')
		digits.append(4)
	while 'R' in s:
		s = remove_word(s, 'THREE')
		digits.append(3)
	while 'T' in s:
		s = remove_word(s, 'TWO')
		digits.append(2)
	while 'I' in s:
		s = remove_word(s, 'NINE')
		digits.append(9)
	while 'O' in s:
		s = remove_word(s, 'ONE')
		digits.append(1)
	digits.sort()
	return ''.join(map(str, digits))

def read_input(filename):
	with open('output.txt', 'w') as output_file:
		with open(filename) as input_file:
			T = int(input_file.readline())
			for i in range(T):
				s = input_file.readline()
				output_file.write('Case #{:d}: {:s}\n'.format(i + 1, solve(s)))

read_input('A-large.in')