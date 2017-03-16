import codejam as gcj
gcj.load_input('B-small-attempt1.in')

T = gcj.read_input('i')
for t in range(T):
	C, J = gcj.read_input('s s')
	c, j = '', ''
	bigger = '-'

	for a, b in zip(C, J):
		if bigger == '-':
			if (a, b) == ('?', '?'):
				c, j = c + '0', j + '0'
			elif a == '?':
				c, j = c + b, j + b
			elif b == '?':
				c, j = c + a, j + a
			else:
				c, j = c + a, j + b
				if a != b:
					bigger = 'C' if int(a) > int(b) else 'J'
		else:
			if a == '?':
				if bigger == 'C':
					c += '0'
				else:
					c += '9'
			else:
				c += a

			if b == '?':
				if bigger == 'J':
					j += '0'
				else:
					j += '9'
			else:
				j += b

	print 'Case #%i:' % (t + 1), c, j

