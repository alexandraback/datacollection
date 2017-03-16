# -*- coding: UTF-8 -*-

import re

def count_str(pattern, string):
    return len(re.findall("(?=%s)" % pattern, string))

def list_words(l,kb):
	return [(w+c) for w in l for c in kb]
	

def algo(inp):
	_ = inp.int
	_ = inp.int
	s = inp.int
	keyboard = inp.str
	pat = inp.str
	print(keyboard)
	print(pat)
	l_words = [""]
	for _ in range(s):
		l_words = list_words(l_words, keyboard)
	max_res = 0
	av_res = 0
	for word in l_words:
		res = count_str(pat, word)
		max_res = max(res, max_res)
		av_res += res
	return max_res - (av_res/len(l_words))
	print("Case end")
	return 0


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
