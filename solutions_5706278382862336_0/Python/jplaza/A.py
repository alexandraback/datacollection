#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from fractions import Fraction

def readline(f):
	return f.readline()[:-1]

def run_program(in_file, out_file):
	cases = int(readline(in_file))
	for i in range(0, cases):
		P, Q = [int(x) for x in readline(in_file).split('/')]
		f = Fraction(P, Q)
		gens = 0
		gen1 = 41
		gen2 = 41
		res = 'impossible'
		if float(f) == 1.0:
			res = 0
		else:
			while gens < 41 and (gen1 > 40 or gen2 > 40):
				val = float(f)
				if val >= 1.0:
					f -= 1
					if gen1 > 40:
						gen1 = gens
				if gen1 <= 40 and f.numerator == 0:
					gen2 = gens
					break
				f *= 2
				gens += 1
		if gen1 <= 40 and gen2 <= 40:
			res = str(gen1)
		out_file.write("Case #%d: %s\n" % (i+1, res))

if __name__ ==  "__main__":
	if len(sys.argv) == 3:
		f = open(sys.argv[1], 'r')
		o = open(sys.argv[2], 'w')
		run_program(f, o)
		f.close()
		o.close()
	else:
		print u"Número de parámetros incorrecto. Se esperan 2."
		print str(sys.argv)

