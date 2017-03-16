# -*- coding: UTF-8 -*-

def is_composite(x):
	if x > 1:
		k = 2
		n = 10000
		while k <= n:
			if x % k == 0: return k
			k += 1
	return 0

def algo(inp):
	n = inp.int
	j = inp.int
	found = set()
	while len(found) < j:
		s = "1"
		for _ in range(n-2): s += str(randint(0,1))
		s += "1"
		comp = [is_composite(int(s,i)) for i in range(2,11)]
		if (0 not in comp):
			res = ret_list([s] + comp)
			if res not in found: print(len(found))
			found.add(res)
		else : print(s, comp)
	return "\n" + ret_list(list(found),"\n")
########################
# Miscaleanous
########################

from fractions import Fraction
from math import sqrt
from random import randint

def cmp_f(x, y):
  """Returns True iff y is within relative or absolute 'epsilon' of x.

  By default, 'epsilon' is 1e-6.
  """
  epsilon = 0.00000001
  # Check absolute precision.
  if -epsilon <= x - y <= epsilon:
    return True

  # Is x or y too close to zero?
  if -epsilon <= x <= epsilon or -epsilon <= y <= epsilon:
    return False

  # Check relative precision.
  return (-epsilon <= (x - y) / x <= epsilon
       or -epsilon <= (x - y) / y <= epsilon)

def ret_list(l,c=' '): return c.join(map(str, l))

########################
# Parsing functions
########################

def read_elements(lines):
	for s in lines:
		for i in s.split(): yield i

class TextGen(object):
	def __init__(self,filename):
		with open(filename,'r') as fichier:
			lines = fichier.readlines()
			self.data = read_elements(lines)

	@property
	def int(self): return int(next(self.data))
	@property
	def str(self): return str(next(self.data))
	@property
	def float(self): return float(next(self.data))
	@property
	def frac(self): return Fraction(float(next(self.data)))
	

########################
# Running...
########################

inname = input("File name ?\n")
infile = "%s.in" % inname
outfile = "%s.out" % inname

inp = TextGen(infile)
cases = inp.int
with open(outfile,'w') as outdata:
	for case in range(1, cases+1):
		print("Starting case %d..." % case)
		outdata.write("Case #%d: %s\n" % (case, algo(inp)))
		print()
