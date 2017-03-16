# Task B
import fileinput

def calc(S, keyboard, cur, word, prob):
	bananas = 0
	for c in keyboard:
		comb = cur + c
		if prob == 0:
			cprob = 1 / len(keyboard)
		else:
			cprob = prob * (1 / len(keyboard))
		if len(comb) == S:
			bananas += comb.count(word) * cprob
		else:
			bananas += calc(S, keyboard, comb, word, cprob)
	return bananas

def calc_max(S, keyboard, cur, word, cmax):
	for c in keyboard:
		comb = cur + c
		if len(comb) == S:
			cmax = max(cmax, comb.count(word))
		else:
			cmax = calc_max(S, keyboard, comb, word, cmax)
	return cmax


def solve(S, keyboard, word):	
	for c in word:
		if keyboard.find(c) == -1:
			return 0.0

	keyweight = {}
	for c in keyboard:
		try:
			keyweight[c] += 1 / len(keyboard)
		except Exception as ex:
			keyweight[c] = 1 / len(keyboard)
	
	bananas = calc(S, keyboard, '', word, 0)
	b_max = calc_max(S, keyboard, '', word, 0)

	return round(b_max - bananas, 6)

stdin = fileinput.input()
T = int(stdin.readline())
for ti in range(T):
	[K, L, S] = stdin.readline().strip().split(' ')
	keyboard = stdin.readline().strip()
	word = stdin.readline().strip()
	print('Case #{0}: {1}'.format(ti+1, float(solve(int(S), keyboard, word))))
