def F(x):
	return any(set(y) <= set([x, 'T']) for y in b + zip(*b) + [[b[i][i] for i in range(4)], [b[i][3 - i] for i in range(4)]])

for _ in range(input()):
	b = [raw_input() for i in range(4)]
	raw_input()
	if F('X'):
		r = 'X won'
	elif F('O'):
		r = 'O won'
	elif ''.join(b).count('.'):
		r = 'Game has not completed'
	else:
		r = 'Draw'
	print ('Case #%d: ' % (_ + 1)) + r
