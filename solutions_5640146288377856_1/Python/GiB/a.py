# -*- coding: UTF-8 -*-

def min_moves_row(n,w): # n-w*q < 2*w
	return n//w - 1

def get_res(n,w):
	return w if n==w else w+1

def algo(inp):
	r = inp.int
	c = inp.int
	w = inp.int
	mm = min_moves_row(c,w)
	res = r * mm
	res += r-1
	c -= w*mm
	return res + get_res(c,w)
	
	


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
