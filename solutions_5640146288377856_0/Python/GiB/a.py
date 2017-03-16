# -*- coding: UTF-8 -*-

tableres = {2:10}
mult = 10
for i in range(3,16):
   tableres[i] = tableres[i-1] + 9 + mult
   mult *= 10
  
print(tableres)

def ispow10(n):
	return n == 10 ** (len(str(n)) - 1)
	
def rev_str(s):
	return s[::-1]

def get_res(ni):
	n = str(ni)
	l = len(n)
	if l == 1: return int(n)
	res = tableres[l]
	if ispow10(ni): return res
	n1 = rev_str(n[:l//2])
	n2 = int(n[l//2:])
	need_rev = 0 if int(n1) == 1 else int(n1)
	if n2: return res+need_rev+n2
	return get_res(ni-1) + 1

def algo(inp):
	n = inp.int
	return get_res(n)
	
	


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
		outdata.write("Case #%d: %s\n" % (case, algo(inp)))
