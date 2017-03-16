
import math
import random

def prime_factors(n):
	upper = int(math.ceil(math.sqrt(n)))+1
	factors = []
	for i in  xrange(2,upper):
		while n%i==0:
			factors.append(i)
			n = n/i
	return factors

def combine_factors(factors):
	while len(factors)>3:
		f = factors.pop(0)
		factors[0] *= f
		factors.sort()
	f = []
	f.append(factors[:])
	while factors.count(2)>1:
		factors[1] = 4
		factors.pop(0)
		factors.sort()
		f.append(factors[:])
	return f

def draw(prob):
	x = random.random()
	tp = 0.0
	for i,p in enumerate(prob):
		tp += p
		if x<=tp:
			return i
	return 0

def guess(numbers):
	counts = [0]*4
	for n in numbers:
		cf = combine_factors(prime_factors(n))
		if len(cf)==1 and len(cf[0])==3 and 2 not in cf[0]:
			return cf[0]
		for factors in combine_factors(prime_factors(n)):
			for f in factors:
				counts[f-2] += 1
	s = sum(counts)
	if s==0:
		counts = [0.25]*4
	else:
		counts = map(lambda x: float(x)/s,counts)
	return [draw(counts)+2 for _ in xrange(3)]

# read the 1
raw_input()
print "Case #1:"

R,N,M,K = map(int,raw_input().split())
for i in xrange(R):
	numbers = map(int,raw_input().split())
	print ''.join(map(str,guess(numbers)))

