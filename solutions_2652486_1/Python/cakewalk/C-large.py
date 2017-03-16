import random
from collections import Counter
import time

start = time.time()

T = int(raw_input())
R, N, M, K = map(int, raw_input().split())
inputproducts = [tuple(sorted(map(int, raw_input().split()))) for r in xrange(R)]


print 'Case #1:'

dictionary = {x: Counter() for x in inputproducts}

try:
	while True:
		Nlist = tuple([random.choice(xrange(2, M+1)) for i in xrange(N)])
		subsets = [[random.choice(xrange(2)) for n in xrange(N)] for k in xrange(K)]
		products = [1]*K
		for k in xrange(K):
			for n in xrange(N):
				if subsets[k][n] == 1:
					products[k] *= Nlist[n]
		products.sort()
		products = tuple(products)
		try:
			dictionary[products][Nlist] += 1
		except:
			pass

except:
	for r in xrange(R):
		#print dictionary[inputproducts[r]].most_common(1)
		try:
			print ''.join(map(str, dictionary[inputproducts[r]].most_common(1)[0][0]))
		except:
			print '2'*N
