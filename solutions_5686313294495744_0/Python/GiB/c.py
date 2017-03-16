# -*- coding: UTF-8 -*-

from queue import PriorityQueue
def get_prio(x,y,a,b):
	mmin = min(x,y)
	return (mmin,x,y,(a,b))

def dic_add(d,x):
	if x in d:
		d[x] += 1
	else: d[x] = 1
	
def algo(inp):
	n = inp.int
	d_first = dict()
	d_sec = dict()
	fir_found = dict()
	sec_found = dict()
	pri = PriorityQueue()
	l = []
	for _ in range(n):
		a = inp.str
		b = inp.str
		l.append((a,b))
		dic_add(d_first, a)
		dic_add(d_sec, b)
	for (a,b) in l:
		x = d_first[a]
		y = d_sec[b]
		entry = get_prio(x,y,a,b)
		print("Entry : ",entry)
		pri.put(entry)
	n_fake = 0
	def reset_queue(pri):
		q2 = PriorityQueue()
		while not pri.empty():
			(_,rx,ry,(a,b)) = pri.get()
			x = d_first[a]
			y = d_sec[b]
			q2.put(get_prio(x,y,a,b))
		return q2
	while not pri.empty():
		(_,rx,ry,(a,b)) = pri.get()
		x = d_first[a]
		y = d_sec[b]
		if x != rx or y != ry:
			pri.put(get_prio(x,y,a,b))
		else:
			entry = get_prio(x,y,a,b)
			print("Rem : ",entry)
			if a in fir_found and b in sec_found:
				n_fake += 1
			elif min(x,y)<=0 and max(x,y)>1:
				n_fake += 1
				d_first[a] -= 1
				d_sec[b] -= 1
			else:
				fir_found[a] = True
				sec_found[b] = True
				d_first[a] = 0
				d_sec[b] = 0
			pri = reset_queue(pri)
	return n_fake

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
