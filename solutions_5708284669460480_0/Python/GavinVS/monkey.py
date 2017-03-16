from collections import defaultdict as ddict

def bananasForString(string, target):
	bananas = 0

	for i in range(len(string) - len(target) + 1):
		if string[i : i + len(target)] == target:
			bananas += 1

	return bananas

def monkey(keys, target, S):
	for letter in target:
		if letter not in keys:
			return 0

	keyProb = ddict(int)

	for letter in keys:
		keyProb[letter] += 1. / len(keys)

	strings = [ '' ]

	for i in range(S):
		newStrings = []
		
		for letter in keyProb:
			for string in strings:
				newStrings.append(string + letter)

		strings = newStrings

	totalBananas = max([bananasForString(s, target) for s in strings])
	paidBananas = 0

	for string in strings:
		prob = 1

		for letter in string:
			prob *= keyProb[letter]

		paidBananas += prob * bananasForString(string, target)

	return totalBananas - paidBananas

def main():
	from sys import stdin
	input = stdin.read().split('\n')
	T = int(input[0])

	for t in range(T):
		K, L, S = map(int, input[3 * t + 1].split())
		keys = input[3 * t + 2]
		target = input[3 * t + 3]

		print "Case #{0}: {1}".format(t + 1, monkey(keys, target, S))

if __name__ == '__main__':
	main()