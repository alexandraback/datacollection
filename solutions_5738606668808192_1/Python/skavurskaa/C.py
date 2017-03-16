import random
import sys
import math

def fact(N):
	for i in xrange(2,10000): # there are enough jamcoins divisible by small numbers
		if N%i==0: return i
	return -1

def getRandomSolution(N, used):
	v = []
	s = '1'
	for i in range(N-2):
		if random.randint(0,1) == 0: s += '1'
		else: s += '0'
	s += '1'

	if s in used:
		return getRandomSolution(N,used)
	for i in range(2,11):
		x = fact(long(s,i))
		if x == -1: return getRandomSolution(N,used)
		else: v.append(x)
	return (s,v)

# main #
random.seed(437812463814)
T = int(raw_input())
N, J = map(int, raw_input().split())
print "Case #1:"

used = {}
while len(used) < J:
	s,v = getRandomSolution(N,used)
	used[s] = v
for s in used:
	sys.stdout.write(s)
	for n in used[s]:
		sys.stdout.write(" " + str(n))
	print ""
