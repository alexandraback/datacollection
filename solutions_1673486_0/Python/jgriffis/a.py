
fin = open("A-small-attempt0.in", 'r')
fout = open("a.out2", 'w')

cases = int(fin.readline().strip())

for i in range(cases):
	numbers = fin.readline().strip().split(' ')
	typed = int(numbers[0])
	total = int(numbers[1])
	left = total - typed
	
	p = []
	prob_line = fin.readline().strip().split(' ')
	probs = [float(f) for f in prob_line]
	
	# Calculate probs for every case
	sits = {}
	for j in range(2**typed):
		format = ""
		prob = 1
		for k in range(typed):
			if j & 2**k > 0:
				prob *= (1 - probs[k])
				format += 'X'
			else:
				prob *= probs[k]
				format += 'O'
		sits[format] = prob

	expecteds = []

	# Keep typing
	keep_exp = 0
	for k in sits.keys():
		keep_exp += sits[k] * (left + 1 + (0 if 'X' not in k else total + 1))
	expecteds.append(keep_exp)

	# Backspace
	for j in range(1, typed + 1):
		back_exp = 0
		for k in sits.keys():
			back_exp += sits[k] * ((j * 2) + left + 1 + (total + 1 if ('X' in k and k.index('X') <= len(k) - j - 1) else 0))
		expecteds.append(back_exp)
	
	# Give up
	expecteds.append(total + 2)

	fout.write('Case #{0}: {1:.6f}\n'.format(i + 1, min(expecteds)))
