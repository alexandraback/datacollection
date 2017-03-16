__author__ = 'leha'

from time import time
from math import factorial
import sys

def nextCase():
    fileName = "B.in"
    fileName = "B-small-attempt0.in"
#    fileName = "B-small-practice.in"
#    fileName = "B-large-practice.in"
    input = open(fileName, 'r')
    T = int(input.readline())
    for i in range(T):
        yield [int(x) for x in input.readline().rstrip().split(' ')]

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
	A, B, K = T

	r = 0
	for a in range(A):
		for b in range(B):
			k = a & b
			if k < K: r += 1

	return r

start = time()

i = 1
for T in nextCase():
    print("Case #%d: %s" % (i, solve(T)))
    i += 1

#print(time() - start)
__author__ = 'leha'
