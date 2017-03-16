# B small
from collections import Counter
def max_possible(keyboard, word, num_presses):
	key_set = set(keyboard)
	for letter in word:
		if letter not in key_set:
			return 0
	for step in xrange(1, len(word)+1):
		assert len(word[step:]) == len(word[:-step])
		if word[step:] == word[:-step]:
			break
	return (num_presses - len(word) + step)/step

def expectation(keyboard, word, num_presses):
	keycount = Counter(keyboard)
	numerator = 1
	for letter in word:
		numerator *= keycount[letter]
	numerator *= max(0, num_presses - len(word) + 1)
	return float(numerator)/pow(len(keyboard), len(word))

def solve(keyboard, word, num_presses):
	return max_possible(keyboard, word, num_presses) - expectation(keyboard, word, num_presses)




#############################################################
if __name__ == '__main__':
	inF = open('test.in')
	case_sols = []
	for case in xrange(int(inF.readline())):
		num_keys, word_length, num_presses = map(int, inF.readline().split())
		keyboard = inF.readline().strip()
		word = inF.readline().strip()
		case_sols.append(solve(keyboard, word, num_presses))

	inF.close()

	B_sol = open('solution.txt', 'w')
	for i, sol in enumerate(case_sols, start=1):
		B_sol.write('Case #{0}: '.format(i) + str(sol) + '\n')

	B_sol.close()