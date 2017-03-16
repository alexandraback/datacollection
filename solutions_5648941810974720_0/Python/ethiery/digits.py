for T in range(1, int(input())+1):
	N = input()
	occurences = {
		'A':0,
		'B':0,
		'C':0,
		'D':0,
		'E':0,
		'F':0,
		'G':0,
		'H':0,
		'I':0,
		'J':0,
		'K':0,
		'L':0,
		'M':0,
		'N':0,
		'O':0,
		'P':0,
		'Q':0,
		'R':0,
		'S':0,
		'T':0,
		'U':0,
		'V':0,
		'W':0,
		'X':0,
		'Y':0,
		'Z':0}
	for c in N:
		occurences[c] += 1

	digits = [0] * 10
	order = ['Z', 'X', 'W', 'G', 'T', 'S', 'R', 'V', 'O', 'I']
	corresp = {
	'Z':(0, 'ZERO'), 
	'X':(6, 'SIX'), 
	'W':(2,'TWO'),
	'G':(8,'EIGHT'), 
	'T':(3,'THREE'), 
	'S':(7,'SEVEN'), 
	'R':(4,'FOUR'), 
	'V':(5,'FIVE'), 
	'O':(1,'ONE'), 
	'I':(9,'NINE')}

	for x in order:
		nb, letters = corresp[x]
		while occurences[x] > 0:
			digits[nb] += 1
			for l in letters:
				occurences[l] -= 1

	number = ""
	for i in range(len(digits)):
		for j in range(digits[i]):
			number += str(i)
			
	print('Case #{}: {}'.format(T, number))
