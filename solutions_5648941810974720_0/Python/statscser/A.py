out = open('outputA_s.txt', 'w')

with open('A-small-attempt0.in', 'r') as f:
	T = int(f.readline())
	for i in range(1, T+1):
		out.write('Case #%s: ' % i)
		S = f.readline().strip()
		letter = {}
		for l in S:
			letter[l] = letter.get(l, 0) + 1

		digit = {}
		if 'Z' in letter:
			num = letter['Z']
			digit[0] = num
			for item in ['Z', 'E', 'R', 'O']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'U' in letter:
			num = letter['U']
			digit[4] = num
			for item in ['F', 'O', 'U', 'R']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'X' in letter:
			num = letter['X']
			digit[6] = num
			for item in ['S', 'I', 'X']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'W' in letter:
			num = letter['W']
			digit[2] = num
			for item in ['T', 'W', 'O']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'G' in letter:
			num = letter['G']
			digit[8] = num
			for item in ['E', 'I', 'G', 'H', 'T']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'F' in letter:
			num = letter['F']
			digit[5] = num
			for item in ['F', 'I', 'V', 'E']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'V' in letter:
			num = letter['V']
			digit[7] = num
			for item in ['S', 'E', 'V', 'E', 'N']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'O' in letter:
			num = letter['O']
			digit[1] = num
			for item in ['O', 'N', 'E']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'T' in letter:
			num = letter['T']
			digit[3] = num
			for item in ['T', 'H', 'R', 'E', 'E']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]
		if 'I' in letter:
			num = letter['I']
			digit[9] = num
			for item in ['N', 'I', 'N', 'E']:
				letter[item] -= num
				if letter[item] == 0:
					del letter[item]

		res = ''
		for i in range(10):
			if i in digit:
				for k in range(digit[i]):
					res += str(i)


		out.write('%s\n' % res)

out.close()

