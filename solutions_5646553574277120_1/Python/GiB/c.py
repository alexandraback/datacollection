# -*- coding: UTF-8 -*-

class EndLoop(Exception):
    pass
	
def algo(inp):
	c = inp.int
	d = inp.int
	v = inp.int
	d_list = []
	for _ in range(d):
		d_list.append(inp.int)
	d_list.sort()
	res = {'unott':1, 'coins':0}
	def create_coin():
		if res['unott'] > v: raise EndLoop
		res['coins'] += 1
		print(res['unott'])
		res['unott'] *= (c+1)
	def add_coin(co):
		res['unott'] += c*co
	try:
		for co in d_list:
			while res['unott'] < co: create_coin()
			add_coin(co)
		while True: create_coin()
	except EndLoop:
		print('Case end')
		return res['coins']
	


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
