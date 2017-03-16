'''
For example, for the jamcoin 1001 mentioned above, a possible set of nontrivial divisors for the base 2 through 10 interpretations of the jamcoin would be: 3, 7, 5, 6, 31, 8, 27, 5, and 77, respectively.c
'''

import sys

#from http://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n
def primes2(n):
	""" Input n>=6, Returns a list of primes, 2 <= p < n """
	n, correction = n-n%6+6, 2-(n%6>1)
	sieve = [True] * (n/3)
	for i in xrange(1,int(n**0.5)/3+1):
		if sieve[i]:
			k=3*i+1|1
			sieve[k*k/3::2*k] = [False] * ((n/6-k*k/6-1)/k+1)
			sieve[k*(k-2*(i&1)+4)/3::2*k] = [False] * ((n/6-k*(k-2*(i&1)+4)/6-1)/k+1)
	return [2,3] + [3*i+1|1 for i in xrange(1,n/3-correction) if sieve[i]]


primeset_small = {int(x):1 for x in primes2(10000)}
primeset_large = {int(x):1 for x in primes2(10000000)}


def calc_divisors(n):
	returner = []
	for i in xrange(2,11):
		nbase = int(n,i)
		#print i,nbase
		notfound = 0
		for key in primeset_small:
			if nbase%key:
				continue
			returner.append(str(key))
			notfound = 0
			break
		if notfound:
			stop =0
			for key in primeset_large:
				if nbase&key:
					continue
				returner.append(str(key))
				stop=1
				notfound = 0
				break
			if stop:
				break
	return returner


print "Case #1:"
#print '111111 '+' '.join(calc_divisors('1000000000000001'))
#print '111111 '+' '.join(calc_divisors('1001111100001111'))

digits=int(sys.argv[1])-2
tries =int(sys.argv[2])

import random

found = 0
while found < tries:
	s='1'
#	print s
	for abc in range(digits):
		s = s+str(random.randint(0,1))
#		print s
	s = s+'1'
#	print s

	divs = calc_divisors(s)
	if len(divs)< 9:
		continue
	else:
		print s + ' ' + ' '.join(divs)
		found += 1
		















