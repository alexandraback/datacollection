#!/usr/bin/env python3

import itertools

def iguales(x, num):
	return (x[0] + x[1] + x[2]) == num

def difthree(x):
	return abs(x[0]-x[1]) < 3 and abs(x[0]-x[2]) < 3 and abs(x[1]-x[2]) < 3

def sorpresa(x):
	return abs(x[0]-x[1]) == 2 or abs(x[0]-x[2]) == 2 or abs(x[1]-x[2]) == 2

def isP(x, p):
	mx = max(x)
	return mx >= p

entrada = open('small-b.in')
salida = open('small-b.out', 'w')
casos = int(entrada.readline())

product = itertools.product(range(11), repeat=3)
product = map(tuple, map(sorted, product))

for i in range(1, casos+1):
	N, S, p, *t = map(int, entrada.readline().split())
	tot = 0
	for num in t:
		#print(product)
		product = itertools.product(range(11), repeat=3)
		product = map(tuple, map(sorted, product))
		normales = set(filter(lambda x:iguales(x, num) and difthree(x), product))
		# print (normales)
		sorpresas = list(filter(sorpresa, normales))
		normales = list(filter(lambda x:not sorpresa(x), normales))

		if normales:
			if isP(normales[0], p):
				tot += 1
			elif sorpresas and isP(sorpresas[0], p) and S:
				tot += 1
				S -= 1
		elif p == 0:
			tot += 1

	#print ('Totales: ', tot)
	salida.write('Case #%d: %d\n' % (i, tot))