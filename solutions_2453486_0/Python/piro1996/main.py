#!/usr/bin/env python

n = int(raw_input())

for i in range(n):
	res = -1
	finish = 1
	field = []

	for j in range(4):
		field.append('')
		field[j] = raw_input()

		if field[j].find('.') != -1:
			finish = 0

		if field[j].count('X') == 4 or (field[j].count('X') == 3 and field[j].count('T') == 1):
			res = 0
		elif field[j].count('O') == 4 or (field[j].count('O') == 3 and field[j].count('T') == 1):
			res = 1

	if res == -1:
		for j in range(4):
			s = ''
			for k in range(4):
				s += field[k][j]

			if s.count('X') == 4 or (s.count('X') == 3 and s.count('T') == 1):
				res = 0
			elif s.count('O') == 4 or (s.count('O') == 3 and s.count('T') == 1):
				res = 1

	if res == -1:
		s = ''
		for j in range(4):
			s += field[j][j]

		if s.count('X') == 4 or (s.count('X') == 3 and s.count('T') == 1):
			res = 0
		elif s.count('O') == 4 or (s.count('O') == 3 and s.count('T') == 1):
			res = 1

	if res == -1:
		s = ''
		for j in range(4):
			s += field[j][3 - j]

		if s.count('X') == 4 or (s.count('X') == 3 and s.count('T') == 1):
			res = 0
		elif s.count('O') == 4 or (s.count('O') == 3 and s.count('T') == 1):
			res = 1

	print 'Case #%d:' % (i + 1),
	if res == -1:
		if finish:
			print 'Draw'
		else:
			print 'Game has not completed'
	elif res == 0:
		print 'X won'
	elif res == 1:
		print 'O won'

	try:
		raw_input()
	except:
		pass
