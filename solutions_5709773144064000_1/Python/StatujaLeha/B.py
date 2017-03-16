__author__ = 'leha'

from time import time
from math import pi

def nextCase():
    fileName = "B.in"
#    fileName = "B-small-attempt0.in"
#    fileName = "B-small-practice.in"
    fileName = "B-large.in"
#    fileName = "B-large-practice.in"
    input = open(fileName, 'r')
    T = int(input.readline())
    for i in range(T):
        C, F, X = tuple([float(x) for x in input.readline().split(' ')])
        yield C, F, X


def solve(T):
	C, F, X = T

	T = 0.0

	rate = 2.0
	while True:
		T1 = T + X/rate
		T2 = T + C/rate + X/(rate + F)
		if T1 <= T2: return T1

		T += C/rate
		rate += F

start = time()

i = 1
for T in nextCase():
    print("Case #%d: %.7f" % (i, solve(T)))
    i += 1

#print(time() - start)
__author__ = 'leha'
