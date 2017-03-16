__author__ = 'leha'

from time import time
from math import pi

def nextCase():
    fileName = "A.in"
    fileName = "A-small-attempt1.in"
#   fileName = "A-small-practice.in"
#   fileName = "A-large-practice.in"
    input = open(fileName, 'r')
    T = int(input.readline())
    for i in range(T):
        A, N = tuple([int(x) for x in input.readline().split(' ')])
        S = [int(x) for x in input.readline().split(' ')]
        yield A, N, S



def solve(T):
	A, N, S = T
	S = list(sorted(S))

	def optimalFix(currWeight, moteWeight):
		count = 0
		s = currWeight

		if 1 == currWeight: return 10**10, currWeight

		while s <= moteWeight:
			count += 1
			s += s - 1

		return count, s

	cache = dict()
	def engine(i, w):
		if i == N: return 0, w

		if (i, w) in cache: return cache[(i, w)]

		if S[i] < w: r, w = engine(i + 1, w + S[i])
		else:
			count, newWeight = optimalFix(w, S[i])
			newWeight += S[i]

			r1, w1 = engine(i + 1, newWeight)
			r1 += count

			r2, w2 = N - i, w

			if r2 > r1: r, w = r1, w1
			else: r, w = r2, w2

		cache[(i, w)] = r, w
		return r, w
			
	r, w  = engine(0, A)
				
	return r

start = time()

i = 1
for T in nextCase():
	print("Case #%d: %s" % (i, solve(T)))
	i += 1

#print(time() - start)
