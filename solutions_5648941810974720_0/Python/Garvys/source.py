T = int(input())


for t in range(T):
	s = str(input())
	dico = dict()
	for w in s:
		if w in dico.keys():
			dico[w] += 1
		else:
			dico[w] = 1

	res = list()
	#ZERO
	if 'Z' in dico.keys() and dico['Z'] > 0:
		nbZ = dico['Z']
		for i in range(nbZ):
			res.append(0)
		dico['Z'] = 0
		dico['E'] -= nbZ
		dico['R'] -= nbZ
		dico['O'] -= nbZ

	#TWO
	if 'W' in dico.keys() and dico['W'] > 0:
		nb = dico['W']
		for i in range(nb):
			res.append(2)
		dico['T'] -= nb
		dico['W'] = 0
		dico['O'] -= nb

	#SIX
	if 'X' in dico.keys() and dico['X'] > 0:
		nb = dico['X']
		for i in range(nb):
			res.append(6)
		dico['S'] -= nb
		dico['I'] -= nb
		dico['X'] = 0

	#FOUR
	if 'U' in dico.keys() and dico['U'] > 0:
		nb = dico['U']
		for i in range(nb):
			res.append(4)
		dico['F'] -= nb
		dico['O'] -= nb
		dico['U'] = 0
		dico['R'] -= nb

	#FIVE
	if 'F' in dico.keys() and dico['F'] > 0:
		nb = dico['F']
		for i in range(nb):
			res.append(5)
		dico['F'] = 0
		dico['I'] -= nb
		dico['V'] -= nb
		dico['E'] -= nb

	#SEVEN
	if 'V' in dico.keys() and dico['V'] > 0:
		nb = dico['V']
		for i in range(nb):
			res.append(7)
		dico['S'] -= nb
		dico['E'] -= nb
		dico['V'] = 0
		dico['E'] -= nb
		dico['N'] -= nb

	#EIGHT
	if 'G' in dico.keys() and dico['G'] > 0:
		nb = dico['G']
		for i in range(nb):
			res.append(8)
		dico['E'] -= nb
		dico['I'] -= nb
		dico['G'] = 0
		dico['H'] -= nb
		dico['T'] -= nb

	#NINE
	if 'I' in dico.keys() and dico['I'] > 0:
		nb = dico['I']
		for i in range(nb):
			res.append(9)
		dico['N'] -= nb
		dico['I'] = 0
		dico['N'] -= nb
		dico['E'] -= nb

	#THREE
	if 'T' in dico.keys() and dico['T'] > 0:
		nb = dico['T']
		for i in range(nb):
			res.append(3)
		dico['T'] = 0
		dico['H'] -= nb
		dico['R'] -= nb
		dico['E'] -= nb
		dico['E'] -= nb

	#ONE
	if 'N' in dico.keys() and dico['N'] > 0:
		nb = dico['N']
		for i in range(nb):
			res.append(1)
		dico['O'] -= nb
		dico['N'] = 0
		dico['E'] -= nb

	res.sort()

	print("Case #{}: {}".format(t+1,''.join(list(map(str,res)))))

