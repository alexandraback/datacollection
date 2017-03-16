#!/usr/bin/python
# -*- coding: UTF-8 -*-
from __future__ import print_function
from collections import *
from random import *

def funfa(products, N, M):
    #print(ident, 'products=%s, N=%d' % (products, N))
    factor_frequency={}
    
    if N == 0:
	for x in products:
	    if x != 1:
		#print(ident, products)
		return
	return [] #Found solution!
    
    pp = list(products)
    pp_count = [0] * len(products)
    
    for factor in range(M, 1, -1):
	factor_frequency[factor] = random()
	for i in range(len(products)):
	    product = products[i]
	    f = factor
	    while f // factor <= N and product % f == 0:
		f *= factor
		factor_frequency[factor] += 1
		
	    while pp[i] % factor == 0:
		pp[i] = pp[i] // factor
		pp_count[i] += 1
		if pp_count[i] > N:
		    return #Impossible to 
		
    #print(ident, 'pp=%s' % (pp))
    #print(ident, 'pp_count=%s' % (pp_count))
    factors = sorted(factor_frequency.keys(), key=lambda x: -factor_frequency[x])

    for factor in factors:
	products2 = [
	    p // factor if p % factor == 0 else p 
	    for p in products
	]
	#print(ident, 'Trying factor=%d' % (factor))
	r = funfa(products2, N-1, M)
	if r is not None:
	    r.append(factor)
	    return r

def readLine():
    return tuple(map(int, raw_input().split(' ')))

(n_tests,) = readLine()
for test in range(1, n_tests+1):
    print('Case #%d:' % (test))
    
    R, N, M, K = readLine()
    for r in range(R):
	prod = list(readLine())

	print(''.join(map(str, sorted(funfa(prod, N, M)))))
