#!/usr/bin/python

from time import time
from sys import argv, stdin
from bisect import *

if argv[1:] == ['generate']:
	def p(x):
		return str(x) == str(x)[::-1]

	def q(x):
		return p(x ** 2) 

	def makep(x, s=''):
		return int(str(x) + str(s) + str(x)[::-1])
	L = [1,2,3]
	try:
		for w in xrange(1,27):
			start = time()
			for i in xrange(2**(w-1),2**w):
				x = makep( bin(i)[2:] )
				if q(x):
					L.append(x)
 
			x = makep( 2*int(bin(2**(w-1))[2:]) )
			if q(x):
				L.append(x)

			for i in xrange(2**(w-1),2**w):
				for s in [0,1,2]:
					x = makep( bin(i)[2:], s )
					if q(x):
						L.append(x)

			for s in [0,1]:
				x = makep( 2*int(bin(2**(w-1))[2:]), s )
				if q(x):
					L.append(x)

			print "Base length of %d done in %f seconds" % (w, time()-start)
	except:
		pass
	print "Found n items with max length of:", len(L), len(str(L[-1] ** 2))

	with open('C.list', 'w') as f:
		L = map(lambda x: x**2, L)
		L = map(str, L)
		print >>f, '\n'.join(L)

else:
	L = open('C.list').read().split()
	L = map(int, L)
	n = int(stdin.readline())
	IN = stdin.readlines()
	IN = map( lambda x : map(int, x.strip().split()), IN)
	for i,(A,B) in enumerate(IN):
		a = bisect_left(L, A)
		b = bisect_right(L, B)
		print "Case #%d: %d" % (i+1, b-a)


