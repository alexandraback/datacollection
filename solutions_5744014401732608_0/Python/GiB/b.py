# -*- coding: UTF-8 -*-

def int_bin(n):
	if n==0: return ""
	return bin(n)[2:]

def resalgo(n):
	return n

def sgen(i,n,res):
	res.append("\n")
	for _ in range(i+1):
		res.append("0")
	for _ in range(n-i-1):
		res.append("1")

def algo(inp):
	n = inp.int
	m = int_bin(inp.int - 1)
	res = []
	if len(m) >= n-1: return "IMPOSSIBLE"
	res.append("POSSIBLE")
	res.append("\n")
	for _ in range(n - len(m) - 1):
		res.append("0")
	res.append(m)
	res.append("1")
	for i in range(1,n):
		sgen(i,n,res)
	return ''.join(res)

########################
# Miscaleanous
########################

from fractions import Fraction

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
