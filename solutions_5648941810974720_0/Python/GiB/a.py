# -*- coding: UTF-8 -*-

def resalgo(s):
	letter_count = dict()
	number_count = dict()
	for c in s:
		if c in letter_count: letter_count[c] += 1
		else: letter_count[c] = 1
	for i in range(10):
		number_count[i] = 0
	numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	def decr_let(d,i):
		if d not in letter_count: return None
		n = letter_count[d]
		if n==0: return None
		number_count[i] += n
		for c in numbers[i]:
			letter_count[c] -= n
			
	decr_let('Z',0)
	decr_let('W',2)
	decr_let('X',6)
	decr_let('U',4)
	decr_let('F',5)
	decr_let('V',7)
	decr_let('G',8)
	decr_let('O',1)
	decr_let('H',3)
	decr_let('I',9)
	
	res = []
	for i in range(10):
		x = str(i)
		for _ in range(number_count[i]):
			res.append(x)
	return "".join(res)
	
def algo(inp):
	n = inp.str
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
