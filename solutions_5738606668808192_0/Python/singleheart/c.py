#!/usr/bin/python
from itertools import * 
from math import sqrt
import subprocess

def isPrime(n):
	return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

def isJamcoin(s):
#print s
	for base in range(2, 10 + 1):
		interpretation = int(s, base)
#		print base, interpretation
		p = subprocess.Popen("factor " + str(interpretation), shell=True, stdout=subprocess.PIPE)
		factors = p.stdout.readline().split(':')[1].split()
		if len(factors) == 1:
			return False
#		print "result " + ' '.join(factors)
	return True

def factors(s):
#	print "factors()"
	factors = [s]
	for base in range(2, 10 + 1):
		interpretation = int(s, base)
		p = subprocess.Popen("factor " + str(interpretation), shell=True, stdout=subprocess.PIPE)
		factors.append(p.stdout.readline().split(':')[1].split()[0])
	return factors


T = input()
for t in range(1, T + 1):
	N, J = [int(x) for x in raw_input().split()]
#	print N, J

	results = []
	start = int('1' + '0'*(N-2) + '1', 2)
	end = int('1'*N, 2)
	for n in range(start, end + 1, 2):
		s = "{0:b}".format(n)
		if isJamcoin(s):
			results.append(factors(s))
		if len(results) >= J:
			break

	print "Case #%d:", t
	for result in results:
		print ' '.join(result)
