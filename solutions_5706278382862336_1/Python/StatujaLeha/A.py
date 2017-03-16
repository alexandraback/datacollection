__author__ = 'leha'

from time import time
from fractions import gcd

def nextCase():
    fileName = "A.in"
#    fileName = "A-small-attempt0.in"
    fileName = "A-large.in"
#    fileName = "A-small-practice.in"
#    fileName = "A-large-practice.in"
    input = open(fileName, 'r')
    T = int(input.readline())
    for i in range(T):
        yield [int(s) for s in input.readline().rstrip().split('/')]

def solve(T):
	p, q = T[0], T[1]

	d = gcd(p, q)
	p, q = p//d, q//d

	if q > 2**40 or (0 != q & (q - 1)): return "impossible"

	e = 1
	while e <= 40:
		if (p*2**e)//q >= 1: return e
		e += 1

	return "impossible"

start = time()

i = 1
for T in nextCase():
    print("Case #%d: %s" % (i, solve(T)))
    i += 1

#print(time() - start)
__author__ = 'leha'
