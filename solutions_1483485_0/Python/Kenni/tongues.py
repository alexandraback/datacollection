#!/usr/bin/python

class Case():
	def __init__(self, number, properties):
		self.__dict__ = properties
		self.number = number
		self.answer = None
	
	def fix_input(self):
		# Fix input
		self.message = self.message[:-1]
		pass
			
	def solve(self):
		# Solve case
		trans = {
			"y": "a", "n": "b", "f": "c", "i": "d",
			"c": "e", "w": "f", "l": "g", "b": "h",
			"k": "i", "u": "j", "o": "k", "m": "l",
			"x": "m", "s": "n", "e": "o", "v": "p",
			"z": "q", "p": "r", "d": "s", "r": "t",
			"j": "u", "g": "v", "t": "w", "h": "x",
			"a": "y", "q": "z", " ": " "
		}

		m = ""
		for c in self.message:
			m += trans[c]

		self.answer = m
	
	def __str__(self):
		return "Case #%d: %s" % (self.number, self.answer)

class CaseParser():
	def __init__(self, infile, parameters):
		self.parameters = parameters

		self.infile = infile
		self.num_cases = None
	
	def cases(self):
		# Get the number of cases
		self.num_cases = int(self.infile.readline())

		for c in xrange(self.num_cases):
			# The properties for this case...
			props = {}
			for p in self.parameters:
				props[p] = self.infile.readline()
		
			yield Case(c+1, props)


if __name__ == "__main__":
	try:
		import sys
		infile_path = sys.argv[1]
	except IndexError:
		infile_path = "infile_path"
	infile = open(infile_path)
	
	params = ["message"]
	
	cp = CaseParser(infile, params)

	for case in cp.cases():
		case.fix_input()
		case.solve()
		print case
