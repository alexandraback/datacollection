# -*- coding: UTF-8 -*-

def powerlist(n,l):
	if l == []: return [n]
	else:
		a = l.pop()
		g = l
		return powerlist(n,l) + powerlist(n+a,g)

def resalgo(n):
	if n == 0: return "INSOMNIA"
	todo = set(['0','1','2','3','4','5','6','7','8','9'])
	# while not(n % 10):
		# todo.discard('0')
		# n //= 10
	x=0
	while todo:
		x += n
		s = set([c for c in str(x)])
		todo -= s
	return x
	
def algo(inp):
	n = inp.int
	return resalgo(n)

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
