replacement = {
	'a': 'y',
	'b': 'n',
	'c': 'f',
	'd': 'i',
	'e': 'c',
	'f': 'w',
	'g': 'l',
	'h': 'b',
	'i': 'k',
	'j': 'u',
	'k': 'o',
	'l': 'm',
	'm': 'x',
	'n': 's',
	'o': 'e',
	'p': 'v',
	'q': 'z',
	'r': 'p',
	's': 'd',
	't': 'r',
	'u': 'j',
	'v': 'g',
	'w': 't',
	'x': 'h',
	'y': 'a',
	'z': 'q'
}

f = open('A-small-attempt0.in')
output = open('ResultA.out', 'w')

cases = int(f.readline())

for i in xrange(1, cases + 1):
	sentence = f.readline()
	result = ''
	
	for letter in sentence:
		if letter == ' ':
			result += ' '
		else:
			for key, value in replacement.iteritems():
				if value == letter:
					result += key
					break
	output.write('Case #' + str(i) + ': ' + result + '\n')
f.close()