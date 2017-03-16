__author__ = 'leha'

from time import time
from math import factorial
from itertools import permutations

def nextCase():
    fileName = "B.in"
    fileName = "B-small-attempt0.in"
#    fileName = "B-small-practice.in"
#    fileName = "B-large-practice.in"
    input = open(fileName, 'r')
    T = int(input.readline())
    for i in range(T):
        input.readline()
        yield [x for x in input.readline().rstrip().split(' ')]

def memoize(function):
    cache = {}
    def decorated_function(*args):
        try:
            return cache[args]
        except KeyError:
            val = function(*args)
            cache[args] = val
            return val
    return decorated_function



def solve(T):
	words = T

	def count(end, used):
		r = 0

		if used == (2**len(words) - 1): return 1

		for w in range(len(words)):
			if 0 == (used & (1 << w)) and end == words[w][0]:
				r += count(words[w][-1], used | (1 << w))

		return r

#	return sum([count(words[w][-1], 1 << w) for w in range(len(words))])
	
	def good(train):
		M = [False] * 30
		
		i = 0
		while i < len(train):
			v = int(train[i], 30) - int('a', 30)
			if M[v]: return False
			M[v] = True
			
			if i == len(train) - 1: break
			while i + 1 < len(train) and train[i] == train[i + 1]: i += 1
			i += 1

		return True

	return sum([1 for p in permutations(words) if good("".join(p))])
			

from itertools import permutations

start = time()

i = 1
for T in nextCase():
    print("Case #%d: %s" % (i, solve(T)))
    i += 1

#print(time() - start)
__author__ = 'leha'
