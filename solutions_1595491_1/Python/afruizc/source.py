#!/usr/bin/env python3

import itertools
from pprint import pprint

def iguales(x, num):
	return (x[0] + x[1] + x[2]) == num

def difthree(x):
	return abs(x[0]-x[1]) < 3 and abs(x[0]-x[2]) < 3 and abs(x[1]-x[2]) < 3

def sorpresa(x):
	return abs(x[0]-x[1]) == 2 or abs(x[0]-x[2]) == 2 or abs(x[1]-x[2]) == 2

def isP(x, p):
	mx = max(x)
	return mx >= p

entrada = open('large.in')
salida = open('large.out', 'w')
casos = int(entrada.readline())

producto = itertools.product(range(11), repeat=3)
producto = set(map(tuple, map(sorted, producto)))

for i in range(1, casos+1):
	N, S, p, *t = map(int, entrada.readline().split())
	tot = 0
	if p == 0:
		tot = N
	else:
		for num in t:
			normales = set(filter(lambda x:iguales(x, num) and difthree(x), producto))
			sorpresas = list(filter(sorpresa, normales))
			normales = list(filter(lambda x:not sorpresa(x), normales))

			if normales:
				if isP(normales[0], p):
					tot += 1
				elif sorpresas and isP(sorpresas[0], p) and S:
					tot += 1
					S -= 1

	salida.write('Case #%d: %d\n' % (i, tot))