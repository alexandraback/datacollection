import fileinput
import sys
import math
import itertools

def count_occurences(sentence, target):
	result = 0
	for i in xrange(0, len(sentence) - len(target) +1):
		if sentence[i:].startswith(target):
			result += 1
	return result

def gen_string(size, keyMap):
	keys = "".join(keyMap.keys())
	for sentence in itertools.imap(''.join, itertools.product(keys, repeat=size)):
		probability = 1.0
		for letter in sentence:
			probability *= keyMap[letter]
		yield (sentence, probability)


def ex2C(line):
	(k,l,s) = [int(x) for x in line.split()]
	keys = sys.stdin.readline().rstrip()
	keyMap = {}
	for key in keys:
		if key in keyMap:
			keyMap[key] += 1
		else:
			keyMap[key] = 1
	keyMap.update({n: 1.0/len(keys) * keyMap[n] for n in keyMap.keys()})
	target = sys.stdin.readline().rstrip()
	
	# checks if the word is reacheable
	for letter in target:
		if letter not in keys:
			# Brign nothing, keep nothing
			return 0.0
	# the probability to get the word on n random letters
	word_probability = reduce(lambda x,y: x * y, [keyMap[letter] for letter in target])

	# SOLUTION 1 ENUMERATE ALL LIKE A PSYCHO!
	weighted_occurences = 0.0
	max_occur = 0
	sentences_tested = 0
	for (sentence, p) in gen_string(s, keyMap):
		# print (sentence , p)
		count = count_occurences(sentence,target)
		max_occur = max(max_occur, count)
		weighted_occurences += count * p

	return max_occur - weighted_occurences

if __name__ == '__main__':
	ncases = int(sys.stdin.readline())
	for i in range(1, ncases + 1 ):
		print "Case #{0}: {1}".format(i, ex2C(sys.stdin.readline().rstrip()))
    	

    	
