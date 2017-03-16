#!/usr/bin/python

class Case():
	def __init__(self, number, properties):
		self.__dict__ = properties
		self.number = number
		self.answer = None
	
	def fix_input(self):
		# Fix input
		self.numbers = map(int, self.numbers.split()[1:])
			
	def solve(self):
		# Solve case
		import itertools
		self.answer = "Impossible"
		combos = {}
		for x in xrange(1, len(self.numbers)):
			for combo in itertools.combinations(self.numbers, x):
				if combos.get(sum(combo)) != None:
					self.answer = '\n'+' '.join(map(str, combos[sum(combo)]))+'\n'+' '.join(map(str, combo))
					return
				else:
					combos[sum(combo)] = combo
	
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
	
	params = ["numbers"]
	
	cp = CaseParser(infile, params)

	for case in cp.cases():
		case.fix_input()
		case.solve()
		print case
